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

int R, C, sy, sx, gy, gx, m[52][52];
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  char  tmp;
  bool  ext = false;
  queue<int>  Q;
  cin >> R >> C >> sy >> sx >> gy >> gx;
  rep(i, 1, R + 1) rep(j, 1, C + 1) {
    cin >> tmp;
    m[j][i] = (tmp == '.') ? -1 : 0;
  }
  // rep(i, 0, R + 2) rep(j, 0, C + 2) {
  //   printf("%lld ", m[j][i]);
  //   if (j == C + 1) printf("\n");
  // }
  Q.push(sx * 52 + sy);
  m[sx][sy] = 0;
  while (!Q.empty()) {
    int q = Q.front();
    Q.pop();
    int qx = q / 52, qy = q % 52;
    for (int d = 0; d < 4; d++) {
      int dx = 0, dy = 0;
      if (d == 0) dx = 1; else if (d == 1) dx = -1; else if (d == 2) dy = 1; else dy = -1;
      // if (qx == sx && qy == sy) printf("%lld %lld", dx, dy);
      if (m[qx + dx][qy + dy] >= 0)
        continue;
      Q.push((qx + dx) * 52 + qy + dy), m[qx + dx][qy + dy] = m[qx][qy] + 1;
      // printf("%lld %lld %lld\n", qx + dx, qy + dy, m[qx + dx][qy + dy]);
      if (qx + dx == gx and qy + dy == gy) {
        ext = true;
        break;
      }
    }
    if (ext) break;
  }
  cout << m[gx][gy] << endl;

  return 0;
}