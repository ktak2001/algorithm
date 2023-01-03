#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 101
int	n, A[MAX], m[MAX][MAX];

int	mcm(int a, int b) {
	int	ans = INT_MAX;
	for (int j = a; j < b; j++)
		ans = min(ans, ((m[a][j] < 0) ? mcm(a, j) : m[a][j]) + ((m[j + 1][b] < 0) ? mcm(j + 1, b) : m[j + 1][b]) + A[a] * A[j + 1] * A[b + 1]);
	m[a][b] = ans;
	return ans;
}

signed main () {
	int	a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i] >> A[i + 1];
	for (int i = 0; i < n; i++)
		memset(m[i], -1, sizeof(m[i]) + 4);
	for (int i = 0; i < n; i++)
		m[i][i] = 0;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++)
	// 		printf(" %d", m[i][j]);
	// 	printf("\n");
	// }
	cout << mcm(0, n - 1) << endl;
	return 0;
}