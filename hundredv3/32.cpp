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

int	w, h, d[8] = {-1, 0, 0, -1, 0, 1, 1, 0};
V	used[31], dst[31];

// dst[h - 1][w - 1]を求めたい

void	chk(int y, int x, V *c, queue<P> *Q) {
	for (int i = 0; i < 8; i += 2) {// 0 2 4 6
		int	a = y + d[i], b = x + d[i + 1];
		// cout << "test1" << endl;
		if (a < 0 || b < 0 || a >= h || b >= w)
			continue ;
		// cout << "test2" << endl;
		if ((c[y][x] >> 0) & 1 && d[i + 1] == 1)
			continue ;
		// cout << "test3" << endl;
		if ((c[y][x] >> 1) & 1 && d[i] == 1)
			continue ;
		// cout << "test4" << endl;
		if (d[i] == -1 && (c[y - 1][x] >> 1) & 1)
			continue ;
		// cout << "test5" << endl;
		if (d[i + 1] == -1 && (c[y][x - 1] >> 0) & 1)
			continue ;
		// cout << "test6" << endl;
		if (!used[a][b]) {
			// cout << "test7" << endl;
			dst[a][b] = dst[y][x] + 1;
			(*Q).push({a, b});
			used[a][b]++;
		}
	}
}

void	maze(V *c) {
	queue<P>	Q;
	Q.push({0, 0});
	used[0][0] = dst[0][0] = 1;
	while (!Q.empty()) {
		int	y = Q.front().ft, x = Q.front().sd;
		// cout << y << " " << x << endl;
		Q.pop();
		chk(y, x, c, &Q);
	}
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	V	ans;
	while (cin >> w >> h, w && h) {
		rep(i, 0, 31) {
			dst[i].assign(31, 0);
			used[i].assign(31, 0);
		}
		// rep(i, 0, 31) rep(j, 0, 31) {
		// 	if (used[i][j])
		// 		cout << "used no:" << i << j << endl;
		// 	if (dst[i][j])
		// 		cout << "dst no:" << i << j << endl;
		// }
		V r(w - 1), g(w); //  bit: 11 下右両方壁 01右だけ壁
		V	c[h];
		rep(i, 0, h)
			c[i].assign(w, 0);
		rep(i, 0, h) {
			if (i < h - 1) {
				rep(j, 0, w - 1)
					cin >> r[j];
				rep(k, 0, w)
					cin >> g[k];
				rep(l, 0, w - 1)
					c[i][l] = r[l] + 2 * g[l];
				c[i][w - 1] = g[w - 1] * 2;
			} else {
				rep(j, 0, w - 1)
					cin >> c[h - 1][j];
			}
		}
		// rep(i, 0, h) rep(j, 0, w) cout << i << " " << j << " " << c[i][j] << endl;
		maze(c);
		ans.push_back(dst[h - 1][w - 1]);
	}
	for (auto itr : ans)
		cout << itr << endl;
	return 0;
}
