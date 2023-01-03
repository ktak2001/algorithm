#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pi;
int	info[100][100];
bool	used[100];

int	prim(const int& V) {
	priority_queue<Pi>	que;
	que.push(Pi());// Pi(0, 0)と同義
	int	ret = 0;
	while (!que.empty()) {
		Pi	p = que.top();
		que.pop();
		if (!~-p.first || used[p.second]++)
			continue;
		ret -= p.first;
		for (int i = 0; i < V; i++)
			que.push(Pi(-info[p.second][i], i));
	}
	return ret;
}

int	main() {
	int	N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &info[i][j]);
		}
	}
	printf("%d\n", prim(N));
	return 0;
}