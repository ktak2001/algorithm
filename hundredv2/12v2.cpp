#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int	n, m, x, y, ans = 0;

signed main() {
	cin >> n;
	bool	con[n][n] = {false};
	cin >> m;
	rep(i, 0, m) {
		cin >> x >> y;
		con[x - 1][y - 1] = con[y - 1][x - 1] = true;
	}
	for (int S = 1 << n; --S;) {
		int	t = bitset<16>(S).count();
		if (t <= ans)
			continue ;
		bool	ok = true;
		rep(j, 0, n) {
			rep(k, 0, j) {
				if (S >> j & S >> k & 1 && !con[j][k])
					ok = false;
			}
		}
		if (ok)
			ans = t;
	}
	cout << ans << endl;
	
	return 0;
}