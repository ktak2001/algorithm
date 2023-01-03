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

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int	n;
	cin >> n;
	rep(i, 0, n) {
		string	str1;
		string	str2;
		cin >> str1 >> str2;
		int	lc[str1.size() + 1][str2.size() + 1] = {};
		rep(j, 0, str1.size()) {
			rep(k, 0, str2.size()) {
				if (str1[j] == str2[k])
					lc[j + 1][k + 1] = lc[j][k] + 1;
				else
					lc[j + 1][k + 1] = max(lc[j][k + 1], lc[j + 1][k]);
				// cout << lc[j + 1][k + 1] << " \n"[k + 1 == str2.size()];
			}
		}
		cout << lc[str1.size()][str2.size()] << endl;
	}
	return 0;
}