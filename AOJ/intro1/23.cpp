#include <iostream>
#include <cstdio>
using namespace std;

int	main()
{
	int	n;
	int	tmp[4];
	int	info[4][3][10] = {};

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
		info[tmp[0] - 1][tmp[1] - 1][tmp[2] - 1] += tmp[3];
	}
	for (int i = 0; i < 4; i++) {
		if (i > 0)
			printf("####################\n");
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++)
				cout << " " <<  info[i][j][k];
			printf("\n");
		}
	}
}