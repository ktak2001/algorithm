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

int n, m[101];
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  VV  d(100, V(100, INF));
  cin >> n;
  rep(i, 0, n)
    cin >> m[i] >> m[i + 1];
  rep(i, 0, n) d[i][i] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j + i < n; j++) {
      for (int k = 0; k < i; k++) {
        d[j][j + i] = min(d[j][j + i], d[j][j + k] + m[j] * m[j + k + 1] * m[j + i + 1] + d[j + k + 1][j + i]);
      }
    }
  }
  cout << d[0][n - 1] << endl;
  return 0;
}