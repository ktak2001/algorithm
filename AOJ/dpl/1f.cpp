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
const int INF = 1LL << 55LL;
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int	N, W, v[100], w[100];
	cin >> N >> W;
	V	d(10001, INF);
	d[0] = 0;
	rep(i, 0, N) cin >> v[i] >> w[i];
	rep(i, 0, N) for (int j = 10000; j >= v[i]; j--) {
		d[j] = min(d[j], d[j - v[i]] + w[i]);
	}
	for (int j = 10000; j >= 0; j--)
		if (d[j] <= W) {
			cout << j << endl;
			break ;
		}

	return 0;
}