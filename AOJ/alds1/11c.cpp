#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define N 100
int	m[N + 1][N + 1] = {}, n, K[N + 1] = {};
int	D[N + 1];
stack<int> S;

void	ds(int id, int dst) {
	for (int i = 1; i <= n; i++) {
		if (m[id][i]) {
			D[i] = min(dst, D[i]);
			S.push(i);
		}
	}
	while(!S.empty()) {
		int	u = S.top();

		ds(u, dst + 1);
		S.pop();
	}
}

int	main() {
	int	u, k, v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		D[i] = -1;
	D[1] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &u, &k);
		if (k) {
			for (int j = 0; j < k; j++) {
				K[u]++;
				scanf("%d", &v);
				m[u][v]++;
			}
		}
	}
	ds(1, 1);
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", i, D[i]);
	}
}