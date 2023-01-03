#include <iostream>
#include <algorithm>
using namespace std;

int	main()
{
	int	a[3] = {};
	for (int i = 0; i < 3; i++) scanf("%d", &a[3]);
	for (int i = 2; i > 0;i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	printf("%d %d %d\n", a[0], a[1], a[2]);
}