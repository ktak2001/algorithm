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

int	n, q, v;
vector<int>	N;

int	chk(int sum, int idx) {
	if (!sum)
		return 1;
	if (sum < 0 || idx == n)
		return 0;
	return chk(sum, idx + 1) || chk(sum - N[idx], idx + 1);
}

signed main() {
	cin >> n;
	N.assign(n, 0);
	rep(i, 0, n)
		cin >> N[i];
	cin >> q;
	rep(i, 0, q) {
		cin >> v;
		cout << (chk(v, 0) ? "yes" : "no") << endl;
	}
	
	return 0;
}