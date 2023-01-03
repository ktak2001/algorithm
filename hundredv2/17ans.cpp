#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
char board[10][10];
bool s[10], b[10], n1[20], n2[20];
bool f(int i, int j, int p) {
	if (p == 8)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		return 1;
	}
	if (i >= 8)
		return 0;
	if (j >= 8)
		return f(i + 1, 0, p);
	bool b00l = 1;
	if (s[i])
		b00l = 0;
	if (b[j])
		b00l = 0;
	if (n1[i + j])
		b00l = 0;
	if (n2[i - j + 7])
		b00l = 0;
	if (!b00l)
		return f(i, j + 1, p);
	else
	{
		s[i] = 1;
		b[j] = 1;
		n1[i + j] = 1;
		n2[i - j + 7] = 1;
		board[i][j] = 'Q';
		if (f(i, j + 1, p + 1))
			return 1;
		s[i] = 0;
		b[j] = 0;
		n1[i + j] = 0;
		n2[i - j + 7] = 0;
		board[i][j] = '.';
		return f(i, j + 1, p);
	}
}
signed main()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = '.';
	bool b00l = 1;
	int n;
	cin >> n;
	for (int p = 0; p < n; p++)
	{
		int i, j;
		cin >> i >> j;
		board[i][j] = 'Q';
		if (s[i])
			b00l = 0;
		s[i] = 1;
		if (b[j])
			b00l = 0;
		b[j] = 1;
		if (n1[i + j])
			b00l = 0;
		n1[i + j] = 1;
		if (n2[i - j + 7])
			b00l = 0;
		n2[i - j + 7] = 1;
	}
	if (!b00l)
	{
		cout << "No Answer\n";
		return 0;
	}
	b00l = f(0, 0, n);
	if (!b00l)
	{
		cout << "No Answer\n";
		return 0;
	}
}