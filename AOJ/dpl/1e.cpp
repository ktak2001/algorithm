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

int	d[1001][1001];

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	string	s1, s2;
	getline(cin, s1), getline(cin, s2);
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (!i or !j) {
				d[i][j] = !i ? j : i;
				continue ;
			}
			int	c = s1[i - 1] == s2[j - 1];
			d[i][j] = min(d[i - 1][j - 1] + c, d[i - 1][j] + 1, d[i][j - 1] + 1);
		}
	}
	cout << d[s1.size()][s2.size()] << endl;

	return 0;
}