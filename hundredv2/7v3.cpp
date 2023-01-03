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
int	n, mx = 0;

int	idx(P p) {
	auto	[x, y] = p;
	return x * 5001 + y + 1;
}

signed main() {
	cin >> n;
	vector<P>	R(n);
	vector<bool>	S(5001 * 5001 + 2, false);
	for(auto& [x, y] : R) {
		cin >> x >> y;
		S[idx(mp(x, y))] = true;
	}
	rep(i, 0, n - 1) {
		rep(j, i, n) {
			int	a = R[i].ft - R[j].ft;
			int	b = R[i].sd - R[j].sd;
			int	sz = a * a + b * b;
			if (sz <= mx)
				continue ;
			if (S[idx({R[i].ft + b, R[i].sd - a})] and S[idx({R[j].ft + b, R[j].sd - a})])
				mx = sz;
		}
	}
	cout << mx << endl;

	return 0;
}	