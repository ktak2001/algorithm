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

int	w, h;
V	ans;

void chk(V *c, V *u, int x, int y, stack<P> *S) {
	rep(i, -1, 2) rep(j, -1, 2) {
		int	a = x + i, b = y + j;
		if (!i && !j)
			continue;
		if (a >= h || a < 0 || b >= w || b < 0)
			continue ;
		if (u[a][b] || !c[a][b])
			continue ;
		(*S).push(mp(a, b));
		u[a][b]++;
	}
}

void	il2(V *c, V *u, stack<P> S) {
	while (!S.empty()) {
		int	x = S.top().ft, y = S.top().sd;
		S.pop();
		chk(c, u, x, y, &S);
	}
}

void	il1(V *c, V *u) {
	int	nm = 0;
	stack<P>	S;
	rep(i, 0, h) {
		rep(j, 0, w) {
			if (c[i][j] && !u[i][j]) {
				u[i][j]++;
				S.push(mp(i, j));
				il2(c, u, S);
				nm++;
			}
		}
	}
	ans.push_back(nm);
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> w >> h;
	while (w && h) {
		int	ans = 0;
		V	c[h], used[h];
		rep(i, 0, h)
			c[i].assign(w, 0), used[i].assign(w, 0);
		rep(i, 0, h)
			rep(j, 0, w)
				cin >> c[i][j];
		il1(c, used);
		cin >> w >> h;
	}
	for (auto itr : ans)
		cout << itr << endl;
	return 0;
}