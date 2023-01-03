#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int	main()
{
	int	W, H, x, y, r;
	cin >> W >> H >> x >> y >> r;

	if ((x >= r && x <= W - r) && (y >= r && y <= H - r))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}