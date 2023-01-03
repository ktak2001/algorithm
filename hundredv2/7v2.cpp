#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
using P = pair<int, int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

signed main() {
	int	n, mx = 0, sz;
	cin >> n;
	vector<int>	X(n), Y(n);
	map<P, int>	M;
	rep(i, 0, n) {
		cin >> X[i] >> Y[i];
		M[mp(X[i], Y[i])] = 1;
	}
	rep(i, 0, n - 1) {
		rep(j, i + 1, n) {
			int	a = X[i] - X[j];
			int	b = Y[i] - Y[j];
			sz = a * a + b * b;
			if (sz <= mx)
				continue ;
			if (!(M.find(mp(X[i] + b, Y[i] - a)) != M.end()))
				continue ;
			if (!(M.find(mp(X[j] + b, Y[i] - a)) != M.end()))
				continue ;
			mx = sz;
		}
	}
	cout << sz << endl;
}