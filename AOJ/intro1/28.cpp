#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int	main()
{
	int	n, m, l;

	cin >> n >> m >> l;
	unsigned long	A[n][m], B[m][l], C[n][l];
	for (int i = 0; i < n; i++)
		memset(C[i], 0, sizeof(long) * l);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < l; j++)
			cin >> B[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			for (int k = 0; k < m; k++)
				C[i][j] += A[i][k] * B[k][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l - 1; j++)
			printf("%lu ", C[i][j]);
		printf("%lu\n", C[i][l - 1]);
	}
	return 0;
}