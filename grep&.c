IP=`ifconfig | grep  -o 'inet addr:[0-9.]\+' | head -n 1 | cut -d ":" -f 2`
grep -o  唯一匹配,不用就会打出整行信息
[合法字符集] 其中 ^a表示不包含该字符'a'
\+ 表示一次到多次匹配，即不停的合法字符集比较
head -n 1 取第一行 负数表示倒数第几行
cut -d  ":" -f 2  以冒号进行切断，然后取第二段

ping -c2 172.16.10.1 | grep -o 'min/avg/max/mdev = [0-9 . /]\+'|cut -d " " -f 3|cut -d "/" -f 2
查看ping 2次后的网络延时

cat /etc/nginx/nginx.conf | grep -Ev '^\s*#' | awk 'BEGIN { RS="[;{}]" } { if ($1 == "pid") print $2 }' | head -n1

反向查找：除了列举的文件，其余全部删除
ls|grep -v 'buf.o\|event.o\|rm.sh\|rtsp.o'|xargs rm -r -f