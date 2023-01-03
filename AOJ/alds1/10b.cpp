#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define N 100
#define INF 1 << 25
int	n, p[N + 1], m[N + 1][N + 1] = {};// pの値は、行列の数プラス1

int	matrixChainMultiplication() {
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	for (int l = 2; l <= n; l++) {// lは、iとjの間の距離を決める。
		for (int i = 1; i <= n - l + 1; i++) {// iは、何番目の行列をスタートとするかを決める。
			int	j = i + l - 1;// iとjの間はl
			m[i][j] = INF;
			for (int k = i; k <= j - 1; k++) {// iとjの間のすべてを検証。
				m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
			}
		}
	}
	return m[1][n];
}

int	main() {
	scanf("%d", &n);
	int	p[n];
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i], &p[i + 1]);
	printf("%d\n", matrixChainMultiplication());
}