很多时候，会有人建议你，如果kill杀不掉一个进程，就用kill -9. 为什么？
kill是Linux下常见的命令。其man手册的功能定义如下：

kill – send a signal to a process

明朗了，其实kill就是给某个进程id发送了一个信号。默认发送的信号是SIGTERM，而kill -9发送的信号是SIGKILL，即exit。exit信号不会被系统阻塞，所以kill -9能顺利杀掉进程。当然你也可以使用kill发送其他信号给进程。
经常使用的killall呢？

killall – kill processes by name

即，通过指定进程名的方式杀死进程。

kill -9
马上 kill. No wait.

kill -9 pid, is sending signal SIGKILL to pid.
kill pid, is sending signal SIGTERM to pid.

The differences are with -9, it kills righ away not waiting for the process id (pid) to do any house keeping work. 
For ex, write any unsafe data to files and then terminate the process.

Do a "kill -l" to see the list of signals that could be sent to a pid.