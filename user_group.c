useradd -m  work 添加一个work用户，并创建其根目录
passwd work  为其创建密码
cat /etc/group 可以查看所有的组里面有哪些用户
groups work  查看work属于哪些组

将一个已有用户 cnzhx 增加到一个已有用户组 apache 中，使此用户组成为该用户的附加用户组，
可以使用带 -a 参数的 usermod  指令。-a 代表 append， 也就是将用户添加到新用户组中而不必离开原有的其他用户组。
不过需要与 -G 选项配合使用：
usermod -a  -G apache cnzhx

如果要同时将 cnzhx 的primary用户组改为 apache，则直接使用 -g 选项：
usermod -g apache cnzhx

如果要将一个用户从某个组中删除，则
gpasswd -d user group
但是这个时候需要保证 group 不是 user 的主组。


 