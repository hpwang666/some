fdisk -l /dev/sda
�鿴sda����Ĵ��̷���

fdisk  /dev/sda  ��ʼ���з�����ɾ���ͽ����������������'m'�鿴�������
'p'������ǰ������Ϣ
�޸����'w'�����޸ı���

�����ĺ�֮������Ĵ��̷�����ʽ��
 mkfs -t ext4 /dev/sda1
 
 
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
	
	