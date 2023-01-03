#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<char>> f(h + 2, vector<char>(w + 2));
	int sh, sw;
	rep(i, h + 2)
	{
		rep(j, w + 2)
		{
			if (i == 0 or i == h + 1 or j == 0 or j == w + 1)
				f[i][j] = 'X';
			else
			{
				cin >> f[i][j];
				if (f[i][j] == 'S')
					sh = i, sw = j;
			}
		}
	}
	int cnt = 0;
	vector<int> dh = {1, 0, -1, 0}, dw = {0, 1, 0, -1};
	rep(i, n)
	{
		vector<vector<int>> ans(h + 2, vector<int>(w + 2, -1));
		ans[sh][sw] = 0;
		queue<pair<int, int>> que;
		que.push(make_pair(sh, sw));
		bool flag = false;
		while (!que.empty())
		{
			pair<int, int> q = que.front();
			que.pop();
			rep(j, 4)
			{
				if (f[q.first + dh[j]][q.second + dw[j]] == 'X')
					continue;
				if (ans[q.first + dh[j]][q.second + dw[j]] >= 0)
					continue;
				ans[q.first + dh[j]][q.second + dw[j]] = ans[q.first][q.second] + 1;
				que.push(make_pair(q.first + dh[j], q.second + dw[j]));
				if (f[q.first + dh[j]][q.second + dw[j]] - '1' == i)
				{
					sh = q.first + dh[j];
					sw = q.second + dw[j];
					cnt += ans[q.first + dh[j]][q.second + dw[j]];
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
	}
	cout << cnt << endl;
}