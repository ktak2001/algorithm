#include <bits/stdc++.h>
#define MAX_N 55
using namespace std;
char mapp[MAX_N][MAX_N];
int n, m, cnt;
int dist[MAX_N][MAX_N];
struct node
{
	int x, y;
} q[MAX_N * MAX_N];
bool pd[MAX_N][MAX_N];
const int r[] = {1, -1, 0, 0}, w[] = {0, 0, 1, -1};
inline void BFS(int sx, int sy)
{
	int hd, tl, dx, dy, fx, fy;
	hd = tl = 1;
	q[1].x = sx;
	q[1].y = sy;
	while (hd <= tl)
	{
		fx = q[hd].x;
		fy = q[hd].y;
		hd++;
		for (int i = 0; i < 4; ++i)
		{
			dx = fx + r[i];
			dy = fy + w[i];
			if (dx < 1 || dy < 1 || dx > n || dy > m || mapp[dx][dy] == '#' || pd[dx][dy] == 1)
				continue;
			pd[dx][dy] = 1;
			tl++;
			q[tl].x = dx;
			q[tl].y = dy;
			dist[dx][dy] = dist[fx][fy] + 1;
			if (dx == n && dy == m)
				return;
		}
	}
}
int main()
{
	memset(dist, 127 / 3, sizeof dist);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> mapp[i][j];
			if (mapp[i][j] == '#')
				cnt++;
		}
	}
	dist[1][1] = 1;
	pd[1][1] = 1;
	BFS(1, 1);
	int ans = n * m - cnt - dist[n][m];
	if (ans < 0)
		puts("-1");
	else
		printf("%d", ans);
	cout << "\n";
	return 0;
}
