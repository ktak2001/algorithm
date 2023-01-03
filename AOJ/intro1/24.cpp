#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int	main()
{
	int	col, row;

	cin	>> row >> col;
	int	vec1[row][col], vec2[col];
	int	vec3[row] = {};
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cin >> vec1[i][j];
	}
	for (int i = 0; i < col; i++)
		cin >> vec2[i];
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++)
			vec3[i] += vec1[i][k] * vec2[k];
	}
	for (int i = 0; i < row; i++)
		printf("%d\n", vec3[i]);
	return 0;
}	