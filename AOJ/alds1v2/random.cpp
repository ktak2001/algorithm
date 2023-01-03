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

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			int	mt = i * j;
			if (mt <= 9)
				cout << " ";
			cout << mt << " \n"[j == 9];
		}
	}
	return 0;
}