
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
	char p = mmp['a'];//�Ҳ�����Ԫ��������Զ�����һ�����key��Ԫ�أ����Խг���3��Ԫ�أ�valueĬ��0��
	mmp['a'] = 'p';
	cout << "a:" << mmp['a'] << endl;
	cout << "size:" << mmp.size() << endl;
	cout << "a++,d++" << endl;
	mmp['a']++;
	mmp['d']++;
	//count �����ҵ�key�ĸ�������Ϊ��map/setĬ����0/1����������count����ѯkey�Ƿ����
	cout << "count d:" << mmp.count('d') <<" d:"<<mmp['d']<< endl;
	cout << "size:" << mmp.size() << endl;
	//���find�˲�֪����Ԫ�أ�˭Ҳ��֪�����ص�ֵ��ɶ������ֱ�����±���..
	//���Ҳ�Ҫ���Բ���һ�������ڵĵ�����������ᱨ��������ڵĵ���������*��ȥȻ����&ȡ��ַ��
	//���ʵ������ȡ��ַ����������ķ�����
	//�Աȷ���ûfind���ķ��ص�������Ȼ��end();
	cout <<"find e(������) address:"<<*(int*)&mmp.find('e') << endl;
	cout <<"end() address:"<< *(int*)&mmp.end()<< endl;
	cout << "Equal?:" << ((mmp.find('e') == mmp.end()) ? "True" : "False") << endl;
	cout << mmp.find('b')->first <<": "<< mmp.find('b')->second << endl;
	char q = mmp['b'];//�ҵ���Ԫ�������ȡֵΪsecond
	system("pause");

	return 0;
}

#endif