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
  int m, n, M;
  V   d(1000, -1);
  d[0] = d[1] = 0;
  cin >> m >> n >> M;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      d[i] += d[j] + 1 + (j == i - j ? 0 : d[i - j]);
    }
  }

}