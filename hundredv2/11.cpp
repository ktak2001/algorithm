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

int	N, M, ans = 0;
int	S[10] = {};
int	k[10], p[10];
int	s[10][10];

void	chk() {
	int	A = 0;
	rep(i, 0, M) {
		int	sum = 0;
		rep(j, 0, k[i]) {
			if (S[s[i][j] - 1])
				sum++;
		}
		if (sum % 2 == p[i])
			A++;
	}
	if (A == M)
		ans++;
}

void	lp(bool t, int idx) {
	if (idx >= 0)
		S[idx] = t;
	if (idx == N - 1) {
		chk();
		return ;
	}
	lp(0, ++idx), lp(1, idx);
}

signed main() {
	cin >> N >> M;
	rep(i, 0, M) {
		cin >> k[i];
		rep(j, 0, k[i])
			cin >> s[i][j];
	}
	rep(i, 0, M)
		cin >> p[i];
	lp(0, -1);
	cout << ans << endl;
	return 0;
}