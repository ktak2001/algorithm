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

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int	n, k;
	cin >> n >> k;
	int	p[n];
	vector<int>	t;
	rep(i, 0, n)
		cin >> p[i];
	int	ok = 1 << 29, ng = 0, mid = 0;
	while (ok - ng > 1) {
		bool	test = true;
		mid = (ok + ng) / 2;
		rep(i, 0, n) {
			if (t.back() + p[i] > mid || t.size() == 0) {
				t.push_back(p[i]);
			} else {
				t.back() += p[i];
			}
			if (t.size() > k || t.back()) {
				test = false;
				break ;
			}
		}
		if (test) {
			ok = mid;
		} else {
			ng = mid;
		}
	}
	cout << mid << endl;
	
	return 0;
}