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
	int	n, m, c[20];
	V	T(50001, INF);	
	T[0] = 0;
	cin >> n >> m;
	rep(i, 0, m) cin >> c[i];
	rep(i, 0, m) for (int j = c[i]; j <= n; j++) {
		T[j] = min(T[j], T[j - c[i]] + 1);
	}
	cout << T[n] << endl;
	return 0;
}