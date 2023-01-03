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

int w, h, c[50][50], chk[50][50];
V sum;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (true) {
    cin >> w >> h;
    if (!w or !h) break ;
    int s = 0;
    rep(i, 0, h) rep(j, 0, w) cin >> c[j][i];
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        if (!c[i][j]) continue;
        c[i][j] = 0;
        queue<int>  Q;
        Q.push(50 * i + j);
        while (!Q.empty()) {
          int q = Q.front();
          Q.pop();
          int qx = q / 50, qy = q % 50;
          for (int y = -1; y <= 1; y++) {
            for (int x = -1; x <= 1; x++) {
              if (qx + x < 0 or qx + x >= w or qy + y < 0 or qy + y >= h)
                continue;
              if (c[qx + x][qy + y]) {
                c[qx + x][qy + y] = 0;
                Q.push((qx + x) * 50 + qy + y);
              }
            }
          }
        }
        s++;
      }
    }
    sum.push_back(s);
  }
  for (auto itr: sum) cout << itr << endl;

  return 0;
}