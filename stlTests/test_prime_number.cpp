#include "stlcontrol.h"

#ifdef TEST_PRIME_NUMBER

#include <iostream>
#include <vector>

using namespace std;

vector <int> prime;

//�ж��Ƿ�Ϊ����
bool isPrime(int p)
{
	if (p % 2 == 0){return false;}
	if (p % 3 == 0){return false;}
	for (int i = 5; i < p / 3; i++)
	{
		if (p%i == 0){ return false; }
	}
	return true;
}

//���������б�
void getPrimeVector(int p)
{
	prime.reserve(500);//����500����λ 
	prime.push_back(2);
	prime.push_back(3);
	for (int i = 5; i < p; i+=2)
	{
		if (isPrime(i))
		{
			prime.push_back(i);
		}
	}
}

//���һ�����ܹ����Ϊ�������������
int getSum(int n)
{
	int t = 0;
	//������������0����ʵ�ǲ��Եı���2+5=7
	if (isPrime(n))
	{
		return 0;
	}
	int st = 0, ed = prime.size() - 1;
	while (prime[ed]>n)
	{
		ed--;
	}
	int et = ed;
	while (prime[st] <= n / 2)
	{
		et = ed;
		while (prime[st] + prime[et] > n)
		{
			et--;
		}
		if (prime[st] + prime[et] == n)
		{
			t++;
		}
		st++;
	}
	return t;
}


int main()
{
	//������������
	getPrimeVector(500);
	cout << "Prime counts:"<<prime.size() << endl;
	for (int i = 0; i < prime.size(); i++)
	{
		cout << prime[i] << " ";
	}
	cout << endl;

	int n;
	while (cin >> n)
	{
		cout << getSum(n) << endl;
	}
	return 0;
}

#endif