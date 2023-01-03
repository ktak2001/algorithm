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

struct edge {
  int from, to, cost;
};

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int vnum, E, r, a, b, c;
  bool isNegative = false;
  cin >> vnum >> E >> r;
  edge e[E];
  V d(1000, INF);
  d[r] = 0;
  rep(i, 0, E) {
    cin >> a >> b >> c;
    e[i].from = a, e[i].to = b, e[i].cost = c;
  }
  for (int i = 0; i < vnum; i++) {
    for (auto [f, t, c]: e) {
      if (d[f] == INF) continue;
      if (d[t] <= d[f] + c) continue;
      if (i == vnum - 1) isNegative = true;
      d[t] = d[f] + c;
    }
  }
  if (isNegative) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i, 0, vnum) {
      if (d[i] == INF)
        cout << "INF" << endl;
      else
        cout << d[i] << endl;
    }
  }

  return 0;
}