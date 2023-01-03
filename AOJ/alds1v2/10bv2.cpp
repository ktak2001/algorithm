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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m[101], db[100][100];
  cin >> n;
  rep(i, 0, n) {
    fill(db[i], db[i] + n, INF);
    db[i][i] = 0;
  }
  rep(i, 0, n) cin >> m[i] >> m[i + 1];
  for (int d = 1; d < n; d++) {
    for (int i = 0; i + d < n; i++) {
      for (int k = 0; k < d; k++) {
        db[i][i + d] = min(db[i][i + d], db[i][i + k] + db[i + k + 1][i + d] + m[i] * m[i + k + 1] * m[i + d + 1]);
      }
    }
  }
  cout << db[0][n - 1] << endl;

  return 0;
}