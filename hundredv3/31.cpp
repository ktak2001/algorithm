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

int	W, H, ans = 0, d1[8] = {-1, 0, 0, -1, 1, 0, 0, 1}, d2[4] = {-1, -1, 1, -1};

void	illum3(vector<V> p, vector<V> *u, int y, int x) {
	queue<P>	Q;
	Q.push({y, x});
	(*u)[y][x] = 1;
	int	len = 0;
	while (!Q.empty()) {
		auto	[b, a] = Q.front();
		Q.pop();
		// cout << b << " two " << a << endl;
		for (int i = 0; i < 8; i += 2) {
			int	s = b + d1[i], t = a + d1[i + 1];
			if (p[s][t])
				len++;
			else if (!(*u)[s][t]) {
				(*u)[s][t] = 1;
				if (s == 1 || s == H || t == 1 || t == W)
					return ;
				Q.push({s, t});
			}
		}
		int	mn = (b % 2 ? -1 : 1);
		for (int i = 0; i < 4; i += 2) {
			int	s = b + d2[i] * mn, t = a + d2[i + 1] * mn;
			if (p[s][t])
				len++;
			else if (!(*u)[s][t]) {
				(*u)[s][t] = 1;
				if (s == 1 || s == H || t == 1 || t == W)
					return ;
				Q.push({s, t});
			}
		}
	}
	ans -= len;
}


void	illum2(vector<V> p, vector<V> *u, int y, int x) {
	queue<P>	Q;
	Q.push({y, x});
	(*u)[y][x] = 1;
	int	len = 0;
	while (!Q.empty()) {
		len += 6;
		auto	[b, a] = Q.front();
		Q.pop();
		// cout << b << " one " << a << endl;
		for (int i = 0; i < 8; i += 2) {
			int	s = b + d1[i], t = a + d1[i + 1];
			if (p[s][t]) {
				len--;
				if (!(*u)[s][t])
					Q.push({s, t}), (*u)[s][t] = 1;
			}
		}
		int	mn = (b % 2 ? -1 : 1);
		for (int i = 0; i < 4; i += 2) {
			int	s = b + d2[i] * mn, t = a + d2[i + 1] * mn;
			if (p[s][t]) {
				len--;
				if (!(*u)[s][t])
					Q.push({s, t}), (*u)[s][t] = 1;
			}
		}
	}
	ans += len;
}

void	illum1(vector<V> p) {
	vector<V> u;
	u.resize(H + 2, V(W + 2, 0));
	rep(i, 1, H + 1) {
		rep(j, 1, W + 1) {
			if (!u[i][j]) {
				if (p[i][j])
					illum2(p, &u, i, j);
				else if (!(i == 1 || i == H || j == 1 || j == W))
					illum3(p, &u, i, j);
			}
		}
	}
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> W >> H;
	vector<V>	p;
	p.resize(H + 2, V(W + 2, 0));
	rep(i, 1, H + 1) rep(j, 1, W + 1)
		cin >> p[i][j];
	illum1(p);
	cout << ans << endl;
	return 0;
}