#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 100000
int	n, q, v, ans = 0;
int	L[MAX + 1];

signed main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		L[i] = v;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> v;
		int	l = 0, r = n;
		while (l + 1 < r) {
			int	mid = (l + r + 1) / 2;
			L[mid] <= v ? l = mid : r = mid;
		}
		ans += L[l] == v;
	}
	cout << ans << endl;
	return 0;
}