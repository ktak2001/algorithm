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
const int INF = 1LL << 52LL;
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	VV	D(21, V(50001, INF));
	int	n, m, c[20];
	cin >> n >> m;
	rep(i, 0, m) cin >> c[i];
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; n - j >= 0; j += c[i]) {
			D[m][n - j] = min(D[m + 1][n - j], D[m])
		}
	}
}