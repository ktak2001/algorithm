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

int	R, C, sum = 0;

signed main() {
	cin >> R >> C;
	bool	Mochi[R][C];
	rep(i, 0, R)
		rep(j, 0, C)
			cin >> Mochi[i][j];
	for (int S = 1 << R; S--; ) {
		int	tmp = 0;
		for (int i = 0; i < C; i++) {
			int	mx = 0;
			for (int j = 0; j < R; j++) {
				if ((S >> j & 1) ^ Mochi[j][i])
					mx++;
			};
			tmp += max(mx, R - mx);
		}
		sum = max(sum, tmp);
	}
	cout << sum << endl;

	return 0;
}