#include <iostream>
#include <algorithm>
using namespace std;

int	main() {
	int	n, u, k, v;
	scanf("%d", &n);
	int	A[n][n] = {};
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &u, &k);
		if (k) {
			for (int j = 0; j < k; j++) {
				scanf("%d", &v);
				A[u - 1][v - 1]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (n > 1) {
			for (int j = 0; j < n - 1; j++) {
				printf("%d ", A[i][j]);
			}
		}
		printf("%d\n", A[i][n - 1]);
	}
	return 0;
}