fdisk -l /dev/sda
�鿴sda����Ĵ��̷���

fdisk  /dev/sda  ��ʼ���з�����ɾ���ͽ����������������'m'�鿴�������
'p'������ǰ������Ϣ
�޸����'w'�����޸ı���

�����ĺ�֮������Ĵ��̷�����ʽ��
 mkfs -t ext4 /dev/sda1
 
 ���ÿ����Զ���ȡĿ¼ /etc/fstab
	 /dev/sda3              /home         ext4      defaults  0      2
	 <dump>  dump ����ͨ����������ʱ������. dump ���������ݣ����������������Ƿ������ļ�ϵͳ���б��ݡ� ����������� 0 �� 1 
	 ��0 ��ʾ���ԣ� 1 ����б��ݡ�
	 �󲿷ֵ��û���û�а�װ dump �� �������Ƕ��� <dump> Ӧ��Ϊ 0��

	<pass> fsck ��ȡ <pass> ����ֵ��������Ҫ�����ļ�ϵͳ�ļ��˳�������������0, 1, ��2�� 
	��Ŀ¼Ӧ�������ߵ�����Ȩ 1, ����������Ҫ�������豸����Ϊ 2. 0 ��ʾ�豸���ᱻ fsck ����顣
 
 ���ݣ� 
dd if=/dev/hdx of=/dev/hdy bs=4096 #�����ص�/dev/hdx���̱��ݵ�/dev/hdy 
dd if=/dev/hdx of=/path/to/image bs=4096 #��/dev/hdxȫ�����ݱ��ݵ�ָ��·����image�ļ� 
dd if=/dev/hdx | gzip >/path/to/image.gz 
#����/dev/hdxȫ�����ݣ�������gzip���߽���ѹ�������浽ָ��·��

���籸��
dd if=/dev/hda bs=16065b | netcat < targethost-IP > 1234 #��Դ������ִ�д������/dev/hda

netcat -l -p 1234 | dd of=/dev/hdc bs=16065b #��Ŀ��������ִ�д��������������ݲ�д��/dev/hdc



����LVM���ж�̬���ַ�����С
˵�������о��鶼���������(/dev/sda1)�������������.����������� ɾ�������Ȼ���߼��������ھ����Ϸ���ģ������չ����ھ����Ŀ¼��

1. ��װ����ʱ����Ҫѡ�����д��̴�С+LVM ����ʱ���ѡ���Ŀ¼��С����Ҫ�������ĵ��������Ժ�Ͳ�����չ��������
2. ϵͳװ�ú�����pvdislay  ���Բ鿴���������ĸ��������档����ΪVG Name�� ubuntu-vg
3. ͨ��vgdisplay  ���Բ鿴���黹ʣ���ٿռ�
4.  �ھ������洴���߼�����СΪ800G������Ϊdata  
		 lvcreate -L 800G -n data  ubuntu-vg
		 mkfs -t ext4 /dev/ubuntu-vg/data
	����lvscan ���Բ鿴�߼���
	
5. �����Զ����� vi /etc/fstab ĩ�����

	/dev/ubuntu-vg/data     /home/work   ext4       defaults        0    0
	
6. df -h ���Կ���
    /dev/mapper/ubuntu--vg-data  788G   69M  748G   1% /home/work
	
	
