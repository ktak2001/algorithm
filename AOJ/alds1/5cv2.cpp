#include <bits/stdc++.h>
using namespace std;
#define int long long
int	n;
double	hnd = 100, zr = 0;

void	Koch(int dpt, double x1, double y1, double x2, double y2) {
	if (!dpt)
		return;
	pair<double, double>	u ((2 * x1 + x2) / 3, (2 * y1 + y2) / 3);
	pair<double, double>	v ((x1 + 2 * x2) / 3, (y1 + 2 * y2) / 2);
	pair<double, double>	t (u.first + cos(M_PI / 3) * (v.first - u.first) - sin(M_PI / 3) * (v.second - u.second), u.second + sin(M_PI / 3) * (v.second - u.second) + cos(M_PI / 3) * (v.first - u.first));
	printf("%.8f %.8f\n", u.first, u.second);
	Koch(dpt - 1, u.first, u.second, t.first, t.second);
	printf("%.8f %.8f\n", t.first, t.second);
	Koch(dpt - 1, t.first, t.second, v.first, v.second);
	printf("%.8f %.8f\n", v.first, v.second);

	return ;
}

signed main() {
	scanf("%d", &n);
	printf("%.8f %.8f\n", zr, zr);
	Koch(n, 0, 0, 100, 0);
	printf("%.8f %.8f\n", hnd, zr);

	return 0;
}