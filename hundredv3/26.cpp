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

int	n, q;

void	rec(V *v, V *ans, int idx, int value) {
	stack<int>	S;
	S.push(idx);
	while (!S.empty()) {
		int	a = S.top();
		S.pop();
		(*ans)[a] += value;
		if (v[a].size())
			for (auto itr : v[a])
				S.push(itr);
	}
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	V	v[n + 1], ans;
	ans.assign(n + 1, 0);
	int	a, b, x, vl;
	rep(i, 0, n - 1) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	rep(i, 0, q) {
		cin >> x >> vl;
		rec(v, &ans, x, vl);
	}
	rep(i, 1, n + 1)
		cout << ans[i] << " \n"[i == n];
	return 0;
}