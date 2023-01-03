#include <iostream>
using namespace std;

void	func(int a, int **num, int idx)
{
	if (idx < 0)
		return ;
	(*num)[idx] = (a % 60);
	if ((a / 60) > 0)
		func(a / 60, num, idx - 1);
}

int	main()
{
	int	a;
	int	*num;

	num = new int[3];
	for (int i = 0; i < 3; i++)
		num[i] = 0;
	cin >> a;
	func(a, &num, 2);
	cout << num[0] << ":" << num[1] << ":" << num[2] << endl;
	return 0;
}