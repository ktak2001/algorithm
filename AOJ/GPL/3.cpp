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

int d[100][100], vN, E, f, t, c;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> vN >> E;
  fill(d, d + vN, INF);
  for (int i = 0; i < E; i++) {
    cin >> f >> t >> c;
    d[f][t] = 0;
  }
  for (int i = 0; i < vN; i++) d[i][i] = 0;
  for (int k = 0; k < vN; k++)
    for (int i = 0; i < vN; i++)
      for (int j = 0; j < vN; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 0; i < vN; i++) if (d[i][i] != 0) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  rep(i, 0, vN) rep(j, 0, vN) {
    if (d[i][j] == INF) cout << "INF" << endl;
    else cout << d[i][j] << endl;
  }

  return 0;
}