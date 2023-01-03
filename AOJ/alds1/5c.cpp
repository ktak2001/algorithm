#include <bits/stdc++.h>
using namespace std;
#define int long long
int	n;

void	Koch(int dp, double x1, double y1, double x2, double y2) {
	printf("%d, depth\n", dp);
	if (!dp)
		return;
	double	vecX = x2 - x1;
	double	vecY = y2 - y1;
	double	dst = sqrt(pow(vecX, 2) + pow(vecY, 2));
	pair<double, double>	fakeXY (cos(60) * dst, sin(60) * dst);
	pair<double, double>	u (vecX / 3, vecY / 3);
	pair<double, double>	v (2 * vecX / 3, 2 * vecY / 3);
	pair<double, double>	T (u.first + fakeXY.first * cos(tanh(vecY / vecX)) - fakeXY.second * sin(tanh(vecY / vecX)), u.second + fakeXY.second * cos(tanh(vecY / vecX)) + fakeXY.first * sin(tanh(vecY / vecX)));

	printf("%f, %f\n", u.first, u.second);
	Koch(dp - 1, u.first, u.second, T.first, T.second);
	printf("%f, %f\n", T.first, T.second);
	Koch(dp - 1, T.first, T.second, v.first, v.second);
	printf("%f, %f\n", v.first, v.second);
	return ;
}

signed main() {
	double	zr = 0;
	double	hd = 100;

	scanf("%d", &n);
	printf("%f, %f\n", zr, zr);
	Koch(n, 0, 0, 100, 0);
	printf("%f, %f\n", hd, zr);

	return 0;
}