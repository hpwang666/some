#!/bin/bash


function start_service
{
case $1 in
 "hdfsipc"):
   start_hdfsipc;;
 "hadoop"):
   start_haoop;;
 "common"):
   start_common;;
 "center"):
   start_center;; 
 "web"):
   start_web;;
 "vms"):
   start_vms;;
 "dist_center"):
   start_dist_center;;
 "mongodb"):
   start_mongodb;;
 "-h"):
     echo "available service and its associated programs"
	 echo "    hadoop: namenode or datanode due to their config"
	 echo "    hdfsipc: vms_hdfs_ipc"
	 echo "    common: vms_fcgi_fpm & vms_agent(php), vms_voicecom"
	 echo "    center: vms_center, vms_dispatch, vms_capture, memcached, vms_upstream, vms_hk_service, vms_agent(c)"
	 echo "    web: nginx"
	 echo "    vms: vms_main, rtspserver"
	 echo "    dist_center: vms_proxy"
	 echo "    mongodb:start mongodb"
	 ;;
esac
}

function start_hdfsipc
{
	if ! pgrep vms_hdfs_ipc >/dev/null; then
		export LD_LIBRARY_PATH=/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server:/home/work/hadoop-2.6.5/lib/native/
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_hdfs_ipc
	fi
}

function start_hadoop
{
	cd /home/work/hadoop-2.6.5; ./start.sh; cd /home/work;
}

function start_web
{
	true
}

function start_common
{
	if ! pgrep vms_fcgi_fpm >/dev/null; then
		cd /home/work/nginx; ./start.sh 2>/dev/null; cd /home/work;
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_fcgi_fpm -n 10 -p 9003 /home/work/vms/vms_fcgi
		/home/work/vms_agent/bin/start.sh
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_voicecom
	fi
}

function start_center
{
	if ! pgrep vms_center >/dev/null; then
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_center
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_dispatch
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/memcached
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_capture
		/home/work/vms_center/bin/start.sh 
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_upstream
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_hk_service
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_agent
	fi
}

function start_vms
{
	if ! pgrep vms_main >/dev/null; then
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_main
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/rtspserver
	fi
}

function start_dist_center
{
	if ! pgrep vms_proxy >/dev/null; then
		/home/work/vms/vms_supervise -D -p /home/work/vms -- /home/work/vms/vms_proxy
	fi
}

function start_mongodb
{
	if [ -f /home/work/hadoop_data/mongodb/mongod_along.conf ]; then 
		mongod -f /home/work/hadoop_data/mongodb/mongod_along.conf
	fi
}

if [ $# -eq 0 ]; then
	cmds=`cat /home/work/services.conf`
else
	cmds=$@
fi

start_common

for item in $cmds; do 
	echo starting $item
	start_service $item;
done
