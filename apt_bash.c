搜索
apt-cache search PostgreSQL

# 删除软件及其配置文件
apt-get --purge remove <package>
# 删除没用的依赖包
apt-get autoremove <package>
# 此时dpkg的列表中有“rc”状态的软件包，可以执行如下命令做最后清理：
dpkg -l |grep ^rc|awk '{print $2}' |sudo xargs dpkg -P




经常会出现不能运行sh脚本，因必须使用bash命令，那是因为默认的是dash
在  bin目录下 ls -l sh 发现指向dash 用以下命令关闭，令其指向bash
sudo dpkg-reconfigure dash

一般可以将/etc/apt/sources.list 里面的下载地址更换，速度快得多
：% s/old/new/g用new替换整篇中出现的old

archive.ubuntu.com
mirrors.aliyun.com















