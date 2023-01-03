#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int	n, ans = 0;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	V	a(n), b(n), c(n);
	rep(i, 0, n)
		cin >> a[i];
	rep(i, 0, n)
		cin >> b[i];
	rep(i, 0, n)
		cin >> c[i];
	sort(all(a)), sort(all(c));
	rep(i, 0, n) {
		int	an = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		int	cn = c.end() - upper_bound(c.begin(), c.end(), b[i]);
		ans += an * cn;
	}
	cout << ans << endl;

	return 0;
}