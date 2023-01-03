#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long lint;

double P;
double dt(double t) {
	return 1.0 + P * pow(2.0, (-2.0 * t / 3.0)) * log(2.0) * (-2.0 / 3.0);
}

int main() {
	cin >> P;

	double left = 0, right = 1010;
	while (right - left > 1e-12) {
		double mid = left + (right - left) / 2;

		if (dt(mid) >= 0)
			right = mid;
		else
			left = mid;
	}

	double time = right;
	double ans = time + P * pow(2.0, (-2.0 * time / 3.0));
	printf("%.16lf\n", ans);
}