#include "stlcontrol.h"

#ifdef TEST_CPP_STATIC

#include <iostream>
using namespace std;
class A
{
private:
	int p;
	void printP(){ cout << " id:" << (int)this << " p : " << p << endl; }
public:
	A(int _p)
	{
		p = _p;
		cout << "Build A";
		printP();
	}
	//这个地方如果换成A a就错啦
	A(A &a)
	{
		p = a.p * 2;
		cout << "Build A";
		printP();
	}
	~A()
	{
		cout << "Clean A";
		printP();
	}
};

//注意ID的区别还有析构的顺序
//一个原理就是加了static就最后析构，否则按照栈的顺序析构
int main()
{
	static A a1(10);
	A a2(a1);
	system("pause");
	return 0;
}

#endif