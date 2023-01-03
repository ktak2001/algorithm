#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
const int maxe = 400005;

struct reader
{
	template <typename Type>
	reader &operator>>(Type &ret)
	{
		int f = 1;
		ret = 0;
		char ch = getchar();
		for (; !isdigit(ch); ch = getchar())
			if (ch == '-')
				f = -f;
		for (; isdigit(ch); ch = getchar())
			ret = (ret * 10) + ch - '0';
		ret *= f;
		return *this;
	}
} fin;

int n, m, x, y, val[maxn];
int lnk[maxn], nxt[maxe], son[maxe], tot;
void add_e(int x, int y)
{
	nxt[++tot] = lnk[x];
	lnk[x] = tot;
	son[tot] = y;
	nxt[++tot] = lnk[y];
	lnk[y] = tot;
	son[tot] = x;
	return;
}

void DFS(int id, int fa)
{
	for (int j = lnk[id]; j; j = nxt[j])
	{
		if (son[j] == fa)
			continue;
		val[son[j]] += val[id];
		DFS(son[j], id);
	}
	return;
}

int main()
{
	fin >> n >> m;
	for (int i = 2; i <= n; i++)
		fin >> x >> y, add_e(x, y);
	while (m--)
		fin >> x >> y, val[x] += y;
	DFS(1, 1);
	for (int i = 1; i <= n; i++)
		printf("%d%c", val[i], " \n"[i == n]);
	return 0;
}