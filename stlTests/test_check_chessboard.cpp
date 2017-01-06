#include "stlcontrol.h"

#ifdef TEST_CHECK_CHESSBOARD

#include <iostream>
#include <string>

using namespace std;


bool isWin(char a, char b, char c, char d, char x)
{
	int p = 0;
	if (a == 'T' || a == x){ p++; }
	if (b == 'T' || b == x){ p++; }
	if (c == 'T' || c == x){ p++; }
	if (d == 'T' || d == x){ p++; }

	if (p == 4)
	{ return true; }
	else
	{
		return false;
	}
}

bool checkwin(char* p, char x)
{
	if (isWin(p[0], p[1], p[2], p[3], x)){return true;}
	if (isWin(p[4], p[5], p[6], p[7], x)){ return true; }
	if (isWin(p[8], p[9], p[10], p[11], x)){ return true; }
	if (isWin(p[14], p[12], p[13], p[15], x)){ return true; }

	if (isWin(p[0], p[1], p[2], p[3], x)){ return true; }
	if (isWin(p[0], p[1], p[2], p[3], x)){ return true; }
	if (isWin(p[0], p[1], p[2], p[3], x)){ return true; }
	if (isWin(p[0], p[1], p[2], p[3], x)){ return true; }

	if (isWin(p[0], p[5], p[10], p[15], x)){ return true; }
	if (isWin(p[3], p[6], p[9], p[12], x)){ return true; }

	return false;
}

void judge(char* p)
{
	bool x = checkwin(p, 'X');
	bool o = checkwin(p, 'O');
	if (x&&o)
	{
		cout << "Draw" << endl;
		return;
	}

	if (x)
	{
		cout << "X won" << endl;
		return;
	}

	if (o)
	{
		cout << "O won" << endl;
		return;
	}
	cout << "Game has not completed" << endl;
}

int main()
{
	char str[16];
	cin.getline(str,16);
	judge(str);
	return 0;
}

#endif