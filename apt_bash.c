����
apt-cache search PostgreSQL

# ɾ��������������ļ�
apt-get --purge remove <package>
# ɾ��û�õ�������
apt-get autoremove <package>
# ��ʱdpkg���б����С�rc��״̬�������������ִ�������������������
dpkg -l |grep ^rc|awk '{print $2}' |sudo xargs dpkg -P




��������ֲ�������sh�ű��������ʹ��bash���������ΪĬ�ϵ���dash
��  binĿ¼�� ls -l sh ����ָ��dash ����������رգ�����ָ��bash
sudo dpkg-reconfigure dash

һ����Խ�/etc/apt/sources.list ��������ص�ַ�������ٶȿ�ö�
��% s/old/new/g��new�滻��ƪ�г��ֵ�old

archive.ubuntu.com
mirrors.aliyun.com















