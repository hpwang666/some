a ：新增， a 的后面可以接字串，而这些字串会在新的一行出现(目前的下一行)
c ：取代， c 的后面可以接字串，这些字串可以取代 n1,n2 之间的行！
d ：删除，因为是删除啊，所以 d 后面通常不接任何咚咚；
i ：插入， i 的后面可以接字串，而这些字串会在新的一行出现(目前的上一行)；
p ：打印，亦即将某个选择的数据印出。通常 p 会与参数 sed -n 一起运行
s ：取代，可以直接进行取代的工作哩！通常这个 s 的动作可以搭配正规表示法！例如 1,20s/old/new/g 就是啦！
实例
 
 
 
 1.数据的搜寻与替换
 sed 's/要被取代的字串/新的字串/g'
 
 /sbin/ifconfig eth0 | grep 'inet addr' | sed 's/^.*addr://g'
  sed -i 's/^M//g' IPsetup.txt   去除windows里面的换行符  ^M的输入先按crtl 再按v 再按m  -i是对文件的直接操作
  
sed -i  '/\/arm-hisiv100nptl-linux\//d' /etc/profile  删除整个带有/arm-hisiv100nptl-linux/的行  其中反斜杠为转义字符
 