#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int	main()
{
	int	x, y;
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x || y)
		{
			if (y < x)
				swap(x, y);
			printf("%d %d\n", x, y);
		}
		else
			break;
	}
	return 0;
}