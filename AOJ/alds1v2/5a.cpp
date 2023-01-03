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

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int	n, q;
	cin >> n;
	V	N(n);
	rep(i, 0, n)
		cin >> N[i];
	vector<bool>	c(2000 * 20 + 1, 0);
	rep(i, 0, (1 << n)) {
		int	a = 0;
		rep(j, 0, n) {
			if (i & (1 << j)) a += N[j];
			c[a] = true;
		}
	}
	cin >> q;
	rep(i, 0, q) {
		int	Q;
		cin >> Q;
		cout << (c[Q] ? "yes" : "no") << endl;
	}
	return 0;
}