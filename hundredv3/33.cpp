#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
using V = vector<int>;
using VV = vector<V>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }

int	h, w, d[] = {0, 1, 0, -1, 1, 0, -1, 0}, sum = 0;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> h >> w;
	VV	s, chk;
	char	c;
	s.assign(h + 2, V(w + 2, 1));
	chk.assign(h + 2, V(w + 2, -1));
	rep(i, 1, h + 1) rep(j, 1, w + 1) {
		cin >> c;
		if (c == '.') {
			sum++;
			s[i][j] = 0;
		}
	}
	queue<P>	q;
	q.push({1, 1});
	chk[1][1] = 0;
	while (!q.empty()) {
		auto	[y, x] = q.front();
		q.pop();
		for (int i = 0; i < 8; i += 2) {
			int	b = y + d[i], a = x + d[i + 1];
			if (chk[b][a] >= 0 || s[b][a])
				continue ;
			chk[b][a] = chk[y][x] + 1;
			if (b == h && a == w) {
				cout << sum - chk[h][w] - 1 << endl;
				return 0;
			}
			q.push({b, a});
		}
	}
	cout << "-1" << endl;
	return 0;
}