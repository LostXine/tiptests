#include "stlcontrol.h"

#ifdef STL_VECTOR_TEST

#include <iostream>
#include <vector>

#include <time.h>

using namespace std;

//Ƕ���ʱ����
inline unsigned __int64 GetCycleCount()
{
	__asm _emit 0x0F
	__asm _emit 0x31
}

class vtest
{
	//win32�е���4�ֽڶ���
private:
	int val;
public:
	vtest(int p) :val(p){ cout << "vtest():" << val << ". Pointer:" << (int)this << endl; }
	~vtest(){ cout << "~vtest():" << val << ". Pointer:" << (int)this << endl; }

	int getVal(){ return val; }
};

//#define CON_ONE //��һ�������,����ֱ��vector<*vtest>push_back(new XX),���clearû�е���������new�����Ķ�����ΪҰָ�룩
//#define CON_TWO	//�ڶ��������,���Բ���ʹ��ָ�������Ч������
#define CON_THREE //����������£�����ʹ��vector<vtest>��ÿ�θ���vector�ߴ綼�����������push_back�Ժ�Ҳ���������
#define CON_THREE_RESERVE //ʹ��reserve����
#define CON_THREE_TIMER //��ʱ����

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
	//��������ʱ��
	unsigned long start, finish;
	//��һ����ʹ��for��[]
	
	cout << "Method 1 - for.at():";
	start = GetCycleCount();
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		vec[i].getVal();
	}
	finish = GetCycleCount();
	cout << (finish - start) << "cycles"<<endl;

	//�ڶ���ʹ�õ�����
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