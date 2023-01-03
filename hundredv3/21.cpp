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

int	n;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n;
	V	h(n), s(n), f(n);
	rep(i, 0, n)
		cin >> h[i] >> s[i];
	int	MX = 0, mx = 0;
	rep(i, 0, n) {
		rep(j, 0, n - i)
			f[i] = h[i] + (n - 1 - i) * s[i];
		sort(f.begin(), f.end());
		f.pop_back();
	}

}