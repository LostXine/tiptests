//里面有测试类和结构体的大小，遍历的速度，push_back进入vector的过程等等。
//#define STL_VECTOR_TEST	//STL的vector测试

//检测一个数能够拆分为多少种质数组合
//#define TEST_PRIME_NUMBER	//包括生成质数列表,判断是否为质数,拆分质数和等函数,不断完善中

//X-O是两个玩家，其中T可以作为任何一方的棋子，定义4*4棋盘，横竖斜线4连即可胜利，检查是否胜利
//#define TEST_CHECK_CHESSBOARD	//检查棋盘是否胜利的程序

//测试cpp中的class，现在测试的是虚函数
//#define TEST_CPP_CLASS
/*
虚函数：可以通过指针调用子类同名函数对于父类的重载
如果不设置虚函数，那么直接使用父类类型的指针指向子类会调用父类的函数，除非使用命名空间
但是如果使用子类类型的指针指向子类，就会调用子类的函数
例如：子类销毁时
如果父类析构函数是虚函数则先调用父类析构再调用子类析构。
如果父类析构不是虚函数，那么只调用父类析构。*/

//测试static顺序还有类的构造方法
//#define TEST_CPP_STATIC

//字符串中不连续回文子串的数量
//#define SUB_PALINDROME

//测试MAP
#define STL_MAP_TEST