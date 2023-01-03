#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define dst(a, b) sqrt(pow(a.ft - b.ft, 2) + pow(a.sd - b.sd, 2))
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second


signed main() {
	int	n;
	cin >> n;
	long double						sum = 0;
	vector<pair<double, double>>	R(n);
	rep(i, 0, n)
		cin >> R[i].ft >> R[i].sd;
	rep (i, 0, n - 1)
		rep(j, i + 1, n)
			sum += (dst(R[i], R[j]) * 2);
	printf("%.10Lf\n", sum / n);
	return 0;
}