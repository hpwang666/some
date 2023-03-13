fdisk -l /dev/sda
查看sda下面的磁盘分区

fdisk  /dev/sda  开始进行分区的删除和建立，具体可以输入'm'查看命令帮助
'p'产看当前分区信息
修改玩后'w'进行修改保存

分区改好之后进行文磁盘分区格式化
 mkfs -t ext4 /dev/sda1
 
 设置开机自动挂取目录 /etc/fstab
	 /dev/sda3              /home         ext4      defaults  0      2
	 <dump>  dump 工具通过它决定何时作备份. dump 会检查其内容，并用数字来决定是否对这个文件系统进行备份。 允许的数字是 0 和 1 
	 。0 表示忽略， 1 则进行备份。
	 大部分的用户是没有安装 dump 的 ，对他们而言 <dump> 应设为 0。

	<pass> fsck 读取 <pass> 的数值来决定需要检查的文件系统的检查顺序。允许的数字是0, 1, 和2。 
	根目录应当获得最高的优先权 1, 其它所有需要被检查的设备设置为 2. 0 表示设备不会被 fsck 所检查。
 
 备份： 
dd if=/dev/hdx of=/dev/hdy bs=4096 #将本地的/dev/hdx整盘备份到/dev/hdy 
dd if=/dev/hdx of=/path/to/image bs=4096 #将/dev/hdx全盘数据备份到指定路径的image文件 
dd if=/dev/hdx | gzip >/path/to/image.gz 
#备份/dev/hdx全盘数据，并利用gzip工具进行压缩，保存到指定路径

网络备份
dd if=/dev/hda bs=16065b | netcat < targethost-IP > 1234 #在源主机上执行此命令备份/dev/hda

netcat -l -p 1234 | dd of=/dev/hdc bs=16065b #在目的主机上执行此命令来接收数据并写入/dev/hdc



利用LVM进行动态划分分区大小
说明：所有卷组都是在物理卷(/dev/sda1)上面虚拟出来的.卷组可以增加 删除物理卷，然后逻辑卷又是在卷组上分配的，并最终挂载在具体的目录下

1. 在装机的时候需要选择所有磁盘大小+LVM ，这时候会选择根目录大小，不要输入最大的的容量，以后就不好扩展其他容量
2. 系统装好后，输入pvdislay  可以查看物理卷挂载哪个卷组上面。卷组为VG Name： ubuntu-vg
3. 通过vgdisplay  可以查看卷组还剩多少空间
4.  在卷组上面创建逻辑卷，大小为800G，名称为data  
		 lvcreate -L 800G -n data  ubuntu-vg
		 mkfs -t ext4 /dev/ubuntu-vg/data
	利用lvscan 可以查看逻辑卷
	
5. 开机自动挂载 vi /etc/fstab 末行添加

	/dev/ubuntu-vg/data     /home/work   ext4       defaults        0    0
	
6. df -h 可以看到
    /dev/mapper/ubuntu--vg-data  788G   69M  748G   1% /home/work
	
	
