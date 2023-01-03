#include <iostream>

using namespace std;
int	main()
{
	int	d;
	for (int i = 1;; i++)
	{
		if (!(cin >> d) || !d)
			break;
		printf("Case %d: %d\n", i, d);
	}
	return 0;
}