#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
const ll INF = 1LL << 60;

vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

int plant_num(char c)
{
	int numc = c - '0';
	if (numc >= 1 && numc <= 9)
		return numc;
	else
		return 0;
}

int main()
{
	int H, W, N;
	cin >> H >> W >> N;
	vector<string> s(H);
	rep(i, H) cin >> s[i];
	int sx, sy;
	rep(i, H) rep(j, W)
	{
		{
			char c = s[i][j];
			if (c == 'S')
			{
				sy = i;
				sx = j;
			}
		}
	}

	vector<vector<int>> dist(H, vector<int>(W, -1));
	queue<int> qh, qw;
	dist[sy][sx] = 0;
	qh.push(sy);
	qw.push(sx);

	int desti = 1, ans = 0;
	while (desti <= N)
	{
		int h = qh.front(), w = qw.front();
		qh.pop();
		qw.pop();

		rep(i, 4)
		{
			int x = w + dx[i], y = h + dy[i];
			if (x < 0 || x >= W || y < 0 || y >= H)
				continue;
			if (s[y][x] == 'X')
				continue;
			if (dist[y][x] != -1)
				continue;

			if (plant_num(s[y][x]) == desti)
			{
				dist[y][x] = dist[h][w] + 1;
				ans += dist[y][x];
				dist.assign(H, vector<int>(W, -1));
				while (!(qh.empty()))
				{
					qh.pop();
					qw.pop();
				}
				desti++;
				dist[y][x] = 0;
				qh.push(y);
				qw.push(x);
				break;
			}
			dist[y][x] = dist[h][w] + 1;
			qh.push(y);
			qw.push(x);
		}
	}
	cout << ans << endl;

	return 0;
}