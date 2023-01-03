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
const int INF = 1LL << 55LL;
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }

int		d[1001][1001] = {};

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string	s1, s2;
	getline(cin, s1), getline(cin, s2);
	rep(i, 0, s1.size() + 1) rep(j, 0, s2.size() + 1) {
		if (!i and !j) continue;
		d[i][j] = INF;
		if (i) d[i][j] = min(d[i - 1][j] + 1, d[i][j]);
		if (j) d[i][j] = min(d[i][j - 1] + 1, d[i][j]);
		if (i && j) d[i][j] = min(d[i][j], d[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
		// cout << d[i][j] << " \n"[j == s2.size()];
	}
	cout << d[s1.size()][s2.size()] << endl;

	return 0;
}