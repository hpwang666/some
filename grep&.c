IP=`ifconfig | grep  -o 'inet addr:[0-9.]\+' | head -n 1 | cut -d ":" -f 2`
grep -o  Ψһƥ��,���þͻ���������Ϣ
[�Ϸ��ַ���] ���� ^a��ʾ���������ַ�'a'
\+ ��ʾһ�ε����ƥ�䣬����ͣ�ĺϷ��ַ����Ƚ�
head -n 1 ȡ��һ�� ������ʾ�����ڼ���
cut -d  ":" -f 2  ��ð�Ž����жϣ�Ȼ��ȡ�ڶ���

ping -c2 172.16.10.1 | grep -o 'min/avg/max/mdev = [0-9 . /]\+'|cut -d " " -f 3|cut -d "/" -f 2
�鿴ping 2�κ��������ʱ

cat /etc/nginx/nginx.conf | grep -Ev '^\s*#' | awk 'BEGIN { RS="[;{}]" } { if ($1 == "pid") print $2 }' | head -n1

