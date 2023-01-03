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

int	k, used[8][8] = {}, p[8];

bool	cst(int x, int y, bool t, bool s) {// t: 0なら確認、1なら代入 s: 0ならusedに0代入。1なら同左。
	int i;
	for (int k = 3; k >= 0; k--) {
		bool	X = (k >> 0) ? x + i : x - i;
		bool	Y = (k >> 1) ? y + i : y - i;
		for (i = 0; X < 8 && X >= 0 && Y < 8 && Y >= 0; i++) {
			if (used[X][Y] && !t)
				return false;
			else if (t)
				used[X][Y] = s;
			cout << X << " " << Y << endl;
		}
		if (t && !k)
			rep(i, 0, 8)
				used[x][i] = used[i][y] = s;
	}
	return true;
}

void	printBoard() {
	rep(i, 0, 8) {
		rep (j, 0, 8)
			(p[i] == j ? (cout << "Q") : (cout << "."));
		cout << endl;
	}
}

void	recursive(int idx) {
	cout << idx << endl;
	if (idx == 8) {
		printBoard();
		return ;
	}
	if (p[idx] >= 0) {
		recursive(idx + 1);
		return ;
	}
	rep(i, 0, 8) {
		if (!cst(idx, i, 0, 0))
			continue ;
		p[idx] = i;
		cst(idx, i, 1, 1);
		recursive(idx + 1);
		p[idx] = -1;
		cst(idx, i, 1, -1);
	}
	return ;
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	rep(i, 0, 8)
		p[i] = -1;
	cin >> k;
	int	x, y;
	rep(i, 0, k) {
		cin >> x >> y;
		p[x] = y;
		cst(x, y, 1, 1);
	}
	printBoard();
	recursive(0);

	return 0;
}