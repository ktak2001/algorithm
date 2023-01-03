#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a) for(int i = 0; i < a; i++)
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
int	dy[] = {-1, 0, 1, 1, 0, -1};
int	dx1[] = {1, 1, 1, 0, -1, 0};
int	dx2[] = {0, 1, 0, -1, -1, -1};

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int	h, w;
	cin >> w >> h;
	VV	a(h + 2, V(w + 2));
	rep(i, h) rep(j, w) cin >> a[i + 1][j + 1];
	int	ans = 0;
	VV	checked(h + 2, V(w + 2));
	queue<P>	que;
	que.push({0, 0});
	checked[0][0] = 1;
	while (!que.empty()) {
		auto	[posy, posx] = que.front();
		que.pop();
		rep(i, 6) {
			int	y = posy + dy[i];
			int	x = posx + ((posx & 1) ? dx1[i] : dx2[i]);
			if (y < 0 || y > h + 1 || x < 0 || x > h + 1)
				continue ;
			if (checked[y][x])
				continue;
			if (a[y][x]) {
				ans++;
				continue;
			}
			checked[y][x] = 1;
			que.push({y, x});
		}
	}
	cout << ans << endl;
	return 0;
}