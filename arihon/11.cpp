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

int N, W;
V   v(100), w(100), d(10001);

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> W;
  rep(i, 0, N) cin >> v[i] >> w[i];
  for (int i = 0; i < N; i++) {
    for (int j = w[i]; j <= W; j++) {
      d[j] = max(d[j], d[j - w[i]] + v[i]);
    }
  }
  cout << d[W] << endl;

  return 0;
}