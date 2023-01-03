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

int	n, W;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> W;
	VV	dp;
	V	v(n), w(n);
	dp.assign(n + 1, V(W + 1, 0));
	rep(i, 0, n)
		cin >> v[i] >> w[i];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= W; j++) {
			if (j < w[i])
				dp[i][j] = dp[i + 1][j];
			else
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
		}
	}
	cout << dp[0][W] << endl;
	return 0;
}