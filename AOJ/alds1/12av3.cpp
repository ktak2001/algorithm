#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 100
int	n, a[MAX][MAX], used[MAX] = {}, cost[MAX];

int	msp() {
	int	ans = 0;
	while (1) {
		int	v = -1;
		for (int i = 0; i < n; i++)
			if ((!used[i] && cost[i] >= 0) && (v < 0 || cost[i] < cost[v]))
				v = i;
		if (v < 0)
			break ;
		used[v] = 1;
		ans += cost[v];
		for (int i = 0; i < n; i++)
			if (!used[i] && a[v][i] >= 0 && (cost[i] < 0 || a[v][i] < cost[i]))
				cost[i] = a[v][i];
	}
	return ans;
}

signed main () {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		cost[i] = a[0][i];
	used[0] = 1;
	cout << msp() << endl;
	return 0;
}