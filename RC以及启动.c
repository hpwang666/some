/etc 目录下面 
rc0.d  关机
rc1.d 最简模式

rc2.d rc3.d rc4.d  都是用户正常模式
每个里面都会有S开头的优先级，数字越大优先级越靠后，最后一个就是S**rc.local
S04rc.local -> ../init.d/rc.local
所有的服务启动脚本都放在/etc/init.d 里面

查看/etc/init.d/rc.local  其启动了各种服务首先会去执行   /etc/rc.local

进入  /etc/rc.local 就是自己的启动服务代码，由于使用了 #!/bin/sh -e 只要脚本有错误就会返回退出
所以建议使用exec执行自己的脚本

  