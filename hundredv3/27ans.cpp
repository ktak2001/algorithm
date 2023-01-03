#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const ll LLINF = 1e18;
const int INF = 1e9;

int M, N;
int ans = 0;
vector<vector<bool>> map_;
void dfs(int x, int y, int len)
{
	map_[x][y] = false;
	if (x != 0 and map_[x - 1][y])
	{
		dfs(x - 1, y, len + 1);
	}
	if (x < N - 1 and map_[x + 1][y])
	{
		dfs(x + 1, y, len + 1);
	}
	if (y != 0 and map_[x][y - 1])
	{
		dfs(x, y - 1, len + 1);
	}
	if (y < M - 1 and map_[x][y + 1])
	{
		dfs(x, y + 1, len + 1);
	}
	map_[x][y] = true;
	ans = max(ans, len);
}

int main()
{
	cin >> M >> N;
	map_.resize(N, vector<bool>(M));
	int I;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> I;
			if (I == 1)
			{
				map_[i][j] = true;
			}
			else
			{
				map_[i][j] = false;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map_[i][j])
			{
				dfs(i, j, 1);
			}
		}
	}
	cout << ans << endl;
}