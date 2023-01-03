/*
	row col table of r*c

*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int	main()
{
	int	r, c, sum = 0;

	cin >> r >> c;
	int	sumr[r], sumc[c], vec[r][c];
	memset(sumr, 0, sizeof(int) * r);
	memset(sumc, 0, sizeof(int) * c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> vec[i][j];
			sumr[i] += vec[i][j];
		}
	}
	for (int i = 0; i < c; i++)	
		for (int j = 0; j < r; j++)
			sumc[i] += vec[j][i];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ", vec[i][j]);
		printf("%d\n", sumr[i]);
		sum += sumr[i];
	}
	for (int i = 0; i < c; i++)
		printf("%d ", sumc[i]);
	printf("%d\n", sum);
	return 0;
}