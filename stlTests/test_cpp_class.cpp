#include "stlcontrol.h"

#ifdef TEST_CPP_CLASS
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Thing
{
public:
	virtual void what_Am_I() { cout << "I am a Thing.\n"; }
	virtual ~Thing(){ cout << "Thing destructor" << endl; }
};
class Animal : public Thing
{
public:
	void what_Am_I() { cout << "I am an Animal.\n"; }
	~Animal(){ cout << "Animal destructor" << endl; }
};

int main()
{
	cout << "Size of int:" << sizeof(int) << endl;
	cout << "Size of HWND:" << sizeof(HWND) << endl;
	//证明两个长度都是4，没毛病
	Thing *t = new Thing;
	Animal*x = new Animal;
	Thing* array[2];
	array[0] = t;
	array[1] = x;
	for (int i = 0; i < 2; i++)
	{
		array[i]->what_Am_I();	//通过指针调用虚函数
	}
	cout << "Delete thing t:" << endl;
	delete array[0];
	cout << "Delete Animal x:" << endl;
	delete array[1];
	cin.ignore();
	return 0;
}
#endif