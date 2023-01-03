#include <iostream>
#include <cstdio>
using namespace std;

int	func(int W)
{
	for (int i = 0; i < W; i++)
		printf("#");
	printf("\n");
}

int	main()
{
	int	H, W;
	while (1)
	{
		cin >> H >> W;
		if (!H && !W)
			return 0;
		func(W);
		for (int i = 1; i < H - 1; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (!j || j == W - 1)
					printf("#");
				else
					printf(".");
			}
			printf("\n");
		}
		func(W);
		printf("\n");
	}
	return 0;
}