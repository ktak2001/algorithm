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

int	N, M, ans = 0, used[13] = {};

void	solve(vector<V>	p, int idx) {
	queue<int>	Q;
	int	mx = 0;
	Q.push(idx);
	while (!Q.empty()) {
		int	x = Q.front();
		used[x]++;
		Q.pop();
		for (auto itr : p[x]) {
			if (!used[itr])
				Q.push(itr);
			used[itr]++;
		}
		mx ++;
	}
	ans = max(ans, mx);
	return ;
}

void	print(vector<V> p) {
	rep(i, 1, N + 1) {
		if (!used[i])
			solve(p, i);
		if (N - i <= ans)
			break ;
	}
	cout << ans << endl;
}

signed main() {
	cin >> N >> M;
	vector<V>	PP(N + 1);
	int	x, y;
	rep(i, 0, M) {
		cin >> x >> y;
		PP[x].push_back(y);
		PP[y].push_back(x);
	}
	print(PP);
	return 0;
}