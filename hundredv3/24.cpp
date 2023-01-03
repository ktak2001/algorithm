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
template <class t, class u>
void chmax(t &a, u b) {
if (a < b)
a = b;
}
template <class t, class u>
void chmin(t &a, u b) {
if (b < a)
a = b;
}

int	n, b, k, a, t = 0, d[101] = {}, f[101] = {};

void	print() {
	rep(i, 1, n + 1)
		cout << i << " " << d[i] << " " << f[i] << endl;
}

void	dpt2(int idx, V *v) {
	for (auto itr : v[idx]) {
		if (!d[itr]) {
			d[itr] = ++t;
			dpt2(itr, v);
			f[itr] = ++t;
		}
	}
}

void	dpt1(V *v) {
	for (int i = 1; i <= n; i++) {
		if (!d[i]) {
			d[i] = ++t;
			dpt2(i, v);
			f[i] = ++t;
		}
	}
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	V	v[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> b >> k;
		rep(j, 0, k) {
			cin >> a;
			v[b].push_back(a);
		}
	}
	dpt1(v);
	print();
	return 0;
}