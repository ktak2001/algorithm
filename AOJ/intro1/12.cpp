#include <cstdio>

int	main()
{
	int	a, b, c;
	int	num = 0;

	scanf("%d%d%d", &a, &b, &c);
	for (int i = a; i <= b; i++)
	{
		if (!(c % i))
			num++;
	}
	printf("%d\n", num);
	return 0;
}