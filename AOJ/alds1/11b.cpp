#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
int	n, color[N] = {}, d[N] = {}, f[N] = {}, ts = 0, m[N][N] = {}, nx = 1;

int	next(int id) {
	for (int i = nx; i < n; i++) {
		if (m[id][i]) {
			nx = i + 1;
			return i;
		}
	}
	return 0;
}

void	dfs2(int id) {
	nx = 1;
	d[id] = ++ts;
	stack<int> S;
	S.push(id);

	while (!S.empty()) {
		int s = S.top();
		int	u = next(s);

		if (u) {
			if (color[u] == WHITE) {
				S.push(u);
				d[u] = ts++;
				color[u] = GRAY;
			}
		}else {
			f[s] = ts++;
			S.pop();
			color[s] = BLACK;
		}
	}

}

void	dfs() {
	for (int i = 1; i <= n; i++) {
		if (color[i])
			dfs2(i);
	}
}

int	main() {
	int	u, k, v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &u, &k);
		if (k) {
			for (int j = 0; j < k; j++) {
				scanf("%d", &v);
				m[u][v]++;
			}
		}
	}
	dfs();
	return 0;
}