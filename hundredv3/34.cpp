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

int	n, f[45] = {};

int	fib(int x) {
	if (f[x] > 0)
		return f[x];
	return fib(x - 1) + fib(x - 2);
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	f[0] = f[1] = 1;
	cout << fib(n) << endl;
	return 0;
}