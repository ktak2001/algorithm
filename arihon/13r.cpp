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
  int n, k;
  V a(100), m(100), d(100001, -1);
  d[0] = 0;
  cin >> n;
  rep(i, 0, n) cin >> a[i] >> m[i];
  cin >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j < a[i]) {
        d[j] = (d[j] < 0 ? d[j] : m[i]);
      } else if (d[j] >= 0) {
        d[j] = m[i];
      } else {
        d[j] = d[j - a[i]] - 1;
      }
    }
  }
  cout << (d[k] >= 0) << endl;

  return 0;
}