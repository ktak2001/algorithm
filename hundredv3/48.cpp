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

int n, w[300], d[300][301];
V   ans;

int rec(int l, int r) {
  if (d[l][r] >= 0) return d[l][r];
  if (r - l == 2)
    return d[l][r] = (abs(w[l] - w[r - 1]) <= 1 ? 2 : 0);
  if (r - l < 2) return d[l][r] = 0;
  if (abs(w[l] - w[r - 1]) <= 1 and rec(l + 1, r - 1) == r - l - 2)
    return d[l][r] = r - l;
  for (int i = l + 1; i < r - 1; i++)
    d[l][r] = max(d[l][r], rec(l, i) + rec(i, r));
  return d[l][r];
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
    cin >> n;
    rep(i, 0, n) rep(j, 0, n + 1) d[i][j] = -1;
    if (n == 0)
      break ;
    rep(i, 0, n) cin >> w[i];
    ans.push_back(rec(0, n));
  }
  for (auto itr: ans) cout << itr << endl;

  return 0;
}