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
  int n, c[100];
  VV   d(100, V(21, 0));
  cin >> n;
  rep(i, 0, n) cin >> c[i];
  d[0][c[0]]++;
  rep(i, 1, n - 1) {
    rep(j, 0, 21) {
      if (j - c[i] >= 0 and d[i - 1][j - c[i]])
        d[i][j] += d[i - 1][j - c[i]];
      if (j + c[i] <= 20 and d[i - 1][j + c[i]])
        d[i][j] += d[i - 1][j + c[i]];
    }
  }
  cout << d[n - 2][c[n - 1]] << endl;

  return 0;
}