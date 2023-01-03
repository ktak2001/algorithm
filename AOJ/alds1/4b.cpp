#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 100000
int	n, q, v, ans = 0;
int	L[MAX + 1];

bool	Binary(int l, int r, int num) {
	int	 mid = (l + r + 1) / 2;

	if (l + 1 == r)
		return L[l] == num;
	if (L[mid] <= num)
		return Binary(mid, r, num);
	else
		return Binary(l, mid, num);
}

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		L[i] = v;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> v;
		ans += Binary(0, n, v);
	}
	cout << ans << endl;
	
	return 0;
}