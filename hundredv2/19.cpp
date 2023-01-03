#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define dst(a, b) sqrt(pow(a.fs - b.fs) + pow(a.sd - b.sd))
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int	D, n, m, ans = 0;

int	Binary(int v, V d) {
	int l = 0, r = D;
	while(l + 1 < r) {
		int	mid = (l + r) / 2;
		if (d[mid] <= v)
			l = mid;
		else
			r = mid;
	}
	return min(abs(v - d[l]), abs(v - d[r]));
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> D >> n >> m;
	V	d1(n), d2(n);
	d1[0] = 0;
	rep(i, 1, n)
		cin >> d1[i];
	rep(i, 0, n)
		d2[i] = D - d1[i];
	sort(d1.begin(), d1.end()), sort(d2.begin(), d2.end());
	rep(i, 0, m) {
		int	v;
		cin >> v;
		ans += min(Binary(v, d1), Binary(v, d2));
	}
	cout << ans << endl;
	return 0;
}