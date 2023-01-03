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
	int	u, k;
	V	v[n + 1], dst(n + 1, -1);
	rep(i, 0, n) {
		cin >> u >> k;
		v[u].assign(k, 0);
		rep(j, 0, k)
			cin >> v[u][j];
	}
	dst[1] = 0;
	queue<int>	Q;
	Q.push(1);
	while (!Q.empty()) {
		int	x = Q.front();
		Q.pop();
		for (auto itr : v[x]) {
			if (dst[itr] < 0) {
				Q.push(itr);
				dst[itr] = dst[x] + 1;
			}
		}
	}
	rep(i, 1, n + 1)
		cout << i << " " << dst[i] << endl;
	return 0;
}