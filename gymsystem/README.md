# 目录结构及作用
```
.
├── admin.txt			管理员数据存储文件
├── guest.txt			顾客数据存储文件
├── gymsystem.cpp		源代码
├── gymsystem.h			头文件：定义了类、特殊功能函数、和UI规范
├── gym.txt				场地数据存储文件
├── makefile			make自动编译
├── order.txt			订单数据存储文件
├── README.md			README
└── sportstype.txt		运动类型数据存储文件

```

# 注意事项
- 由于我没有写预处理宏，所以不同系统上执行的命令不同，为了调试程序功能并且你的系统是windows的话，你需要：
	1. 头文件和源文件中的所有`system("clear")`均改为`system("cls")`
	2. 源文件中`exit(0)`均改为`exit`
-  各组员今早看懂自己的模块原理，不明白的可以问我