
#include "stlcontrol.h"

#ifdef STL_MAP_TEST
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char, int> mmp;
	mmp['c'] = 'd';
	mmp['b'] = 's';
	cout << "c:" << mmp['c'] << endl;
	char p = mmp['a'];//找不到的元素这里会自动增加一个这个key的元素（所以叫成了3个元素，value默认0）
	mmp['a'] = 'p';
	cout << "a:" << mmp['a'] << endl;
	cout << "size:" << mmp.size() << endl;
	cout << "a++,d++" << endl;
	mmp['a']++;
	mmp['d']++;
	//count 可以找到key的个数，因为是map/set默认是0/1个，可以用count来查询key是否存在
	cout << "count d:" << mmp.count('d') <<" d:"<<mmp['d']<< endl;
	cout << "size:" << mmp.size() << endl;
	//如果find了不知道的元素，谁也不知道返回的值是啥，所以直接用下标多好..
	//而且不要尝试查找一个不存在的迭代器，程序会报错，如果存在的迭代器可以*过去然后用&取地址。
	//如果实在是想取地址可以用下面的方法↓
	//对比发现没find到的返回迭代器果然是end();
	cout <<"find e(不存在) address:"<<*(int*)&mmp.find('e') << endl;
	cout <<"end() address:"<< *(int*)&mmp.end()<< endl;
	cout << "Equal?:" << ((mmp.find('e') == mmp.end()) ? "True" : "False") << endl;
	cout << mmp.find('b')->first <<": "<< mmp.find('b')->second << endl;
	char q = mmp['b'];//找到的元素这里会取值为second
	system("pause");

	return 0;
}

#endif