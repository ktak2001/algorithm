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

int	D[100][100];
int	n;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<P >	M(n);
	rep(i, 0, n) {
		D[i][i] = 0;
		cin >> M[i].first >> M[i].second;
	}
	rep(i, 1, n) {
		for (int j = 0; j + i < n; j++) {
			D[j][j + i] = INF;
			for (int k = 0; k < i; k++) {
				D[j][j + i] = min(D[j][j + i], M[j].first * M[j + k].second * M[j + i].second + D[j][j + k] + D[j + k + 1][j + i]);
			}
			cout << "j: "<< j << " j + i:" << j + i << " D" << D[j][j + i] << endl;
		}
	}
	cout << D[0][n - 1] << endl;

	return 0;
}