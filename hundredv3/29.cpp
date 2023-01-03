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

int	R, C, d[8] = {0, 1, 0, -1, 1, 0, -1, 0}, ans = 0;
P	S, G;

int	dfs(vector<V> c, vector<V> u) {
	queue<P>	Q;
	Q.push({S.ft, S.sd});
	u[S.ft][S.sd] = 0;
	while (!Q.empty()) {
		int	x = Q.front().ft, y = Q.front().sd;
		Q.pop();
		for (int i = 0; i < 8; i += 2) {
			int	a = x + d[i], b = y + d[i + 1];
			if (a == G.ft && b == G.sd)
				return u[x][y] + 1;
			if (c[a][b] && u[a][b] < 0) {
				u[a][b] = u[x][y] + 1;
				Q.push({a, b});
			}
		}
	}
	return 0;
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	cin >> S.ft >> S.sd >> G.ft >> G.sd;
	vector<V>	c, used;
	char	s;
	c.resize(R + 2, V(C + 2)), used.resize(R, V(C));
	rep(i, 0, R)
		used[i].assign(C, -1);
	rep(i, 0, R + 2) rep(j, 0, C + 2) {
		if (i == 0 || i == R + 1 || j == 0 || j == C + 1)
			c[i][j] = 0;
		else {
			cin >> s;
			c[i][j] = (s == '.' ? 1 : 0);
		}
	}
	cout << dfs(c, used) << endl;

	return 0;
}