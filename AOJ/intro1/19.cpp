#include <iostream>
#include <cstdio>
using namespace std;

int	main()
{
	int	H, W;

	while (1)
	{
		int	sign = 0;
		cin >> H >> W;
		if (!H || !W)
			return 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = sign % 2; j < W + sign % 2; j++)
			{
				if (!(j % 2))
					printf("#");
				else
					printf(".");
			}
			printf("\n");
			sign++;
		}
		printf("\n");
	}
}