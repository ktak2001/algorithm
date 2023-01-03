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

int n, k, p[101][7], a, b, sum = 0;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  bool Z = true;
  cin >> n >> k;
  rep(i, 0, k) {
    cin >> a >> b;
    p[a][0] = b;
    if (a == 1)
      Z = false;
  }
  if (Z) rep(i, 1, 4) p[1][i] = 1;
  rep(i, 1, n + 1) {
    bool ok = p[i][0] > 0;
    rep(j, 1, 4) {
      j = ok ? p[i][0] : j;
      rep(k, 1, 7) {
        if (j == k) p[i][j + 3] += p[i - 1][k];
        else if (j + 3 != k)
          p[i][j] += p[i - 1][k];
      }
      p[i][j] %= 10000;
      if (ok)
        break ;
    }
  }
  rep(i, 1, 7)
    sum += p[n][i];
  cout << sum % 10000 << endl;

  return 0;
}