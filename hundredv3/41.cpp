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

int D, N, mT[200], c[200][3], sum = 0, d[200][2];
V   mx(200, 0), mn(200, 100);

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> D >> N;
  rep(i, 0, D) cin >> mT[i];
  rep(i, 0, N) rep(j, 0, 3) cin >> c[i][j];
  rep(i, 0, D) {
    rep(j, 0, N) {
      if (c[j][0] <= mT[i] and c[j][1] >= mT[i])
        mx[i] = max(mx[i], c[j][2]), mn[i] = min(mn[i], c[j][2]);
    }
    if (i > 0) {
      d[i][0] = max(abs(mn[i] - mx[i - 1]) + d[i - 1][1], abs(mn[i] - mn[i - 1]) + d[i - 1][0]);
      d[i][1] = max(abs(mx[i] - mx[i - 1]) + d[i - 1][1], abs(mx[i] - mn[i - 1]) + d[i - 1][0]);
    }
  }
  cout << max(d[D - 1][0], d[D - 1][1]) << endl;

  return 0;
}