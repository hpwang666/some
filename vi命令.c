zt zz zb 分别是让光标显示在屏幕的上  中  底部

备份当前文件main.cpp到main.cpp.bak:  :w % %.bak

:e ./harttle    " 编辑该目录
:Explore .      " 浏览该目录
:Sexplore .     " 在水平分割窗口中浏览该目录
:Vexplore .     " 在垂直分割窗口中浏览该目录
打开目录后Enter进入下一层，-返回上一层，R重命名，D删除。

ctags 用法
	安装ctags 后 对目录执行ctags -R . 当前目录  子目录文件都生成tags文件
	生成tags文件后 即可进行函数跳转
	Ctrl + ]  跳转到函数的定义
	Ctrl + t  回跳

bn bp 上下操作
b name 或者是序号b5 直接跳转
b# 表示前一个文件 ls里面可以看到
badd 添加文件但不显示
bdelete==bd 删除缓冲区的文件

复制操作
　　yy命令复制当前整行的内容到vi缓冲区
　　yw复制当前光标所在位置到单词尾字符的内容到vi缓存区，相当于复制一个单词
	y$复制光标所在位置到行尾内容到缓存区
　　y^复制光标所在位置到行首内容到缓存区
　　#yy例如：5yy就是复制5行
	3，5y复制第三行到第五行内容到缓存区
	
单词:
	w 下一个单词头
	e 下一个单词尾部
	b 前一个单词的头部
	yaw 复制一个完整的单词  当光标在单词中间时使用
	#yaw 复制几个完整的单词
替换
　　:s/old/new用new替换行中首次出现的old
　　: s/old/new/g 用new替换行中所有出现的old
　　:#,# s/old/new/g用new替换从第＃行到第＃行中出现的old
　　：% s/old/new/g用new替换整篇中出现的old
    : 1,$s/word1/word2/gc 
　　如果替换的范围较大时，在所有的命令尾加一个c命令，强制每个替换需要用户进行确认，例如:s/old/new/c 或s/old/new/gc

缩进：
	>>
	5>>  以下5行集体缩进

格式化:
	== 格式化本行
	#= 格式化以下多少行 这个功能比较智能，蛮好用

可视模式：
	v 字符选取
	V 行选取
	通过jk  翻页来选取内容
	y复制
	p粘贴
	d删除

di( 括号内的全部删除
di{ 大括号内的全部删除
dw 删除一个单词

行内操作光标：
	0 移动到行头
	^ 移动到本行的第一个不是 blank 字符
	$ 移动到行尾
	w 光标移动到下一个单词的开头
	e 光标移动到下一个单词的结尾

分屏操作：
Ctrl +w v 左右分屏
		c 关闭当前分屏
		l 光标在左屏幕
		h 光标在右屏幕
		L 当前分屏移动到右边
		H 当前分屏移动到左边

寄存器：
	命令行模式下 registers 可以看到所有寄存器的值
	" 上一次复制或者删除的文本
	0-9 文本复制删除的历史
	ctrl+r 可以选择提取寄存器的值 c+r " 就是上次复制的值
	
外部拷贝：
	外部拷贝都放在 + 寄存器里面
	命令5put+ 粘贴在第5行后面 
	直接输入"+p 分号是寄存器标识  将+中的内容粘贴
	
	"+yw   复制一个单词到系统剪切寄存器	
	V "+y  选中的内容复制到系统剪切寄存器
	
	
	
	
