#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int	N, K, ans = LLONG_MAX;

signed main() {
	cin >> N >> K;
	int	a[N];
	rep(i, 0, N)
		cin >> a[i];
	for (int i = 0; i < (1 << N); i++) {
		if (__builtin_popcount(i) == K) {
			int	p = 0, tmp = 0;
			rep (j, 0, N) {
				if (i >> j & 1) {
					if (p < a[j]) {
						p = a[j];
					} else {
						tmp += p - a[j] + 1;
						p++;
					}
				} else if (p < a[j]) {
					p = a[j];
				}
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}