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