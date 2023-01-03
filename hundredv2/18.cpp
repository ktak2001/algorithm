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

int	n, q, v, ans = 0;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	V	s(n);
	rep(i, 0, n)
		cin >> s[i];
	cin >> q;
	rep(i, 0, q) {
		cin >> v;
		int	l = 0, r = n;
		while (l + 1 != r) {
			int	mid = (l + r) / 2;
			if (s[mid] <= v)
				l = mid;
			else
				r = mid;
		}
		if (s[l] == v)
			ans++;
	}
	cout << ans << endl;
	return 0;
}