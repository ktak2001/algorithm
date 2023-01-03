#include <iostream>
#include <cstdio>
using namespace std;

int	main()
{
	int	n, x;
	int	ans;

	while (1) {
		cin >> n >> x;
		if (!n && !x)
			return 0;
		ans = 0;
		for (int i = 1; i <= n - 2; i++) {
			for (int j = i + 1; j <= n - 1; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (i + j + k == x)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
}