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

int	n, m, sum;

int	recurse(V T, int idx, int dpt, int s) {
	if (dpt == 4 || T[idx] > s || idx == n || s < T[idx])
		return s;
	int	mn = recurse(T, idx + 1, dpt, s);
	for (int i = 1; dpt < 4 && s >= i * T[idx]; i++)
		mn = min(mn, recurse(T, idx + 1, ++dpt, s - i * T[idx]));
	return mn;
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	V	T(n + 1), Q;
	T[0] = 0;
	rep(i, 1, n + 1)
		cin >> T[i];
	int	k = 0;
	rep(i, 0, n + 1)
		rep(j, i, n + 1)
			Q.push_back(T[i] + T[j]);
	sort(all(Q));
	Q.erase(unique(Q.begin(), Q.end()), Q.end());
	int	l = 0, x = Q.size(), r = x - 1, ans = 0;
	for (; l < x; l++) {
		while (l <= r and Q[l] + Q[r] > m)
			r--;
		if (l > r)
			break ;
		ans = max(ans, Q[l] + Q[r]);
	}
	cout << ans << endl;

	return 0;
}