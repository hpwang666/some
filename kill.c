�ܶ�ʱ�򣬻����˽����㣬���killɱ����һ�����̣�����kill -9. Ϊʲô��
kill��Linux�³����������man�ֲ�Ĺ��ܶ������£�

kill �C send a signal to a process

�����ˣ���ʵkill���Ǹ�ĳ������id������һ���źš�Ĭ�Ϸ��͵��ź���SIGTERM����kill -9���͵��ź���SIGKILL����exit��exit�źŲ��ᱻϵͳ����������kill -9��˳��ɱ�����̡���Ȼ��Ҳ����ʹ��kill���������źŸ����̡�
����ʹ�õ�killall�أ�

killall �C kill processes by name

����ͨ��ָ���������ķ�ʽɱ�����̡�

kill -9
���� kill. No wait.

kill -9 pid, is sending signal SIGKILL to pid.
kill pid, is sending signal SIGTERM to pid.

The differences are with -9, it kills righ away not waiting for the process id (pid) to do any house keeping work. 
For ex, write any unsafe data to files and then terminate the process.

Do a "kill -l" to see the list of signals that could be sent to a pid.