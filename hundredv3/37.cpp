#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
using V = vector<int>;
using VV = vector<V>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }

int	n, m, ans = 0;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	V	c(m);
	rep(i, 0, m)
		cin >> c[i];
	sort(c.begin(), c.end());
	for (int i = m - 1; i >= 0; i--) {
		int	j;
		for (j = 0; n - j * c[i] >= 0; j++) ;
		ans += j - 1;
		n -= (j - 1) * c[i];
		if (!n)
			break ;
	}
	cout << ans << endl;

	return 0;
}