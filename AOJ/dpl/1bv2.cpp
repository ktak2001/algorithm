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
	V	D(10001, -1);
	D[0] = 0;
	cin >> N >> W;
	rep(i, 0, N) cin >> v[i] >> w[i];
	rep(i, 0, N) for (int j = W; j >= w[i]; j--) {
		D[j] = max(D[j], D[j - w[i]] + v[i]);
	}
	cout << D[W] << endl;
	return 0;
}