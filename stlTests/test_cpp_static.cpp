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
	//����ط��������A a�ʹ���
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

//ע��ID��������������˳��
//һ��ԭ����Ǽ���static�����������������ջ��˳������
int main()
{
	static A a1(10);
	A a2(a1);
	system("pause");
	return 0;
}

#endif