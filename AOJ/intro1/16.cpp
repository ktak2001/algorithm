#include <iostream>
#include <algorithm>
using namespace std;

int	main()
{
	int	n;
	int	tmp;

	cin >> n;
	int	amax = -1e7;
	int	amin = 1e7;
	long long	int	asum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		amax = max(tmp, amax);
		amin = min(tmp, amin);
		asum += tmp;
	}
	cout << amin << " " << amax <<  " " << asum << endl;
}