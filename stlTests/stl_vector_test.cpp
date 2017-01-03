#include "stlcontrol.h"

#ifdef STL_VECTOR_TEST

#include <iostream>
#include <vector>

#include <time.h>

using namespace std;

//嵌入计时函数
inline unsigned __int64 GetCycleCount()
{
	__asm _emit 0x0F
	__asm _emit 0x31
}

class vtest
{
	//win32中的类4字节对齐
private:
	int val;
public:
	vtest(int p) :val(p){ cout << "vtest():" << val << ". Pointer:" << (int)this << endl; }
	~vtest(){ cout << "~vtest():" << val << ". Pointer:" << (int)this << endl; }

	int getVal(){ return val; }
};

//#define CON_ONE //第一种情况下,测试直接vector<*vtest>push_back(new XX),结果clear没有调用析构（new出来的东西成为野指针）
//#define CON_TWO	//第二种情况下,测试测试使用指针变量，效果如上
#define CON_THREE //第三种情况下，测试使用vector<vtest>，每次更改vector尺寸都会调用析构，push_back以后也会调用析构
#define CON_THREE_RESERVE //使用reserve命令
#define CON_THREE_TIMER //计时命令

int main()
{
	cout << "Different sizeof" << endl;
	cout << "sizeof(bool):" << sizeof(bool) << endl;
	cout << "sizeof(char):" << sizeof(char) << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(float):" << sizeof(float) << endl;
	cout << "sizeof(double):" << sizeof(double) << endl;
	cout << "sizeof(long):" << sizeof(long) << endl;
	cout << endl;

#if (defined CON_ONE) || (defined CON_TWO)
	vector<vtest*> vec;
#endif
#if defined CON_THREE
	vector<vtest> vec;
#ifdef CON_THREE_RESERVE
	vec.reserve(100);
#endif
#endif
	for (int i = 0; i < 100; i++)
	{
		cout << "loop " << i << " start." << endl;
#ifdef CON_ONE
		vec.push_back(new vtest(i));
#endif
#ifdef CON_TWO
		vtest* tmp = new vtest(i);
		vec.push_back(tmp);
#endif
#ifdef CON_THREE
		vec.push_back(vtest(i));
#endif
		cout << "vec.size():" << vec.size() << endl;
		cout << "loop " << i << " done." << endl;
	}
	cout << "vec.push_back done." << endl;

#ifdef CON_THREE_TIMER
	//测量遍历时间
	unsigned long start, finish;
	//第一种是使用for和[]
	
	cout << "Method 1 - for.at():";
	start = GetCycleCount();
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		vec[i].getVal();
	}
	finish = GetCycleCount();
	cout << (finish - start) << "cycles"<<endl;

	//第二种使用迭代器
	cout << "Method 2 - while iterator:";
	start = GetCycleCount();
	vector<vtest>::iterator tp = vec.begin();
	while (tp != vec.end())
	{
		tp->getVal();
		tp++;
	}
	finish = GetCycleCount();
	cout << (finish - start) << "cycles" << endl;

	cout << "vec.timer done." << endl;
#endif;
	vec.clear();
	cout << "vec.clear() done." << endl;
	cin.ignore();

}

#endif