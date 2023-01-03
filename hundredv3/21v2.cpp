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

int	n;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	V	h(n), s(n);
	rep(i, 0, n)
		cin >> h[i] >> s[i];
	int	l = 1LL<<60, r = 0;
	rep(i, 0, n) {
		chmin(l, h[i]);
		chmax(r, h[i] + s[i] * (n - 1));
	}
	while (l + 1 < r) {
		int		mid = (r + l) / 2;
		bool	f = 1;
		V		cnt(n + 1, 0);
		rep(i, 0, n) {
			if (mid < h[i])
				f = false;
			else {
				int	x = (mid - h[i]) / s[i];
				cnt[min(n, x)]++;
			}
		}
		int	add = 0;
		rep(i, 0, n) {
			add += cnt[i];
			if (add > i + 1)
				f = false;
		}
		if (f)
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;

	return 0;
}