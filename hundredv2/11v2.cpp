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

int	N, M, ans;

signed main() {
	cin >> N >> M;
	vector<V>	s(M);
	vector<int>	k(M);
	vector<int>	p(M);
	rep(i, 0, M) {
		cin >> k[i];
		s[i].resize(k[i]);
		rep(j, 0, k[i]) {
			cin >> s[i][j];
			s[i][j]--;
		}
	}
	rep(i, 0, M)
		cin >> p[i];
	ans = 1 << N;
	rep(i, 0, (1 << N)) {
		int		c = 0;
		rep(j, 0, M) {
			rep(l, 0, k[j]) {
				if ((i >> s[j][l] & 1))
					c++;
			}
			if (p[j] != c % 2) {
				ans--;
				break ;
			}
		}
	}
	cout << ans << endl;
	return 0;
}