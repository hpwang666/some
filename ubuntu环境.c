输入如下命令,该命令以引导分区为(hd0,gpt3)为例
ls  查看挂载点
set root=(hd0,gpt3)/boot/grub

set prefix=(hd0,gpt3)/boot/grub

insmod normal

normal

按照如上步骤输入normal后将正确进入引导界面。然后进入系统

你以为这样就结束了吗，你还是太年轻了
在你再一次重启后还是会发现，没有变化，还是那个错误

你需要在正确进入Linux系统后，输入如下命令修复引导

sudo update-grub

sudo grub-install /dev/sda

不过在输入第二条命令后，我的电脑竟然提示grub-install: warning: this GPT partition label contains no BIOS Boot Partition; embedding won’t be possible，遇到这种情况后，可以输入一下命令

parted /dev/sda set 1 bios_grub on

parted /dev/sda print

最后再输入一次sudo grub-install /dev/sda，之后应该就没有问题了

##########
卸载vmware tool 
vmware-uninstall-tools.pl


####
ubuntu ssh不断开
vi /etc/ssh/sshd_config
	ClientAliveInterval 30
	ClientAliveCountMax 6




