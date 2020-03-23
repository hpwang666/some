fdisk -l /dev/sda
查看sda下面的磁盘分区

fdisk  /dev/sda  开始进行分区的删除和建立，具体可以输入'm'查看命令帮助
'p'产看当前分区信息
修改玩后'w'进行修改保存

分区改好之后进行文磁盘分区格式化
 mkfs -t ext4 /dev/sda1
 
 
 备份： 
dd if=/dev/hdx of=/dev/hdy bs=4096 #将本地的/dev/hdx整盘备份到/dev/hdy 
dd if=/dev/hdx of=/path/to/image bs=4096 #将/dev/hdx全盘数据备份到指定路径的image文件 
dd if=/dev/hdx | gzip >/path/to/image.gz 
#备份/dev/hdx全盘数据，并利用gzip工具进行压缩，保存到指定路径

网络备份
dd if=/dev/hda bs=16065b | netcat < targethost-IP > 1234 #在源主机上执行此命令备份/dev/hda

netcat -l -p 1234 | dd of=/dev/hdc bs=16065b #在目的主机上执行此命令来接收数据并写入/dev/hdc