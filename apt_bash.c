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

% s/archive.ubuntu.com/mirrors.aliyun.com/g

清华大学镜像网站
https://mirrors.tuna.tsinghua.edu.cn/
% s/archive.ubuntu.com/mirrors.tuna.tsinghua.edu.cn/g



安装apt-cache以外的包

sudo add-apt-repository ppa:git-core/ppa # 向 PPA 中添加 git 的软件源
sudo apt-get update
sudo apt-get install git


添加PPA不成功可以执行以下操作
我们先重装一遍CA证书：
sudo apt-get install --reinstall ca-certificates
如果还不行，我们就绕过代理，加一个"-E"：
sudo -E add-apt-repository --update ppa:ubuntu-toolchain-r/test














