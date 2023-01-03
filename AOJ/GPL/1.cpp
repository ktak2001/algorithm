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

struct  edge {
  int to, cost;

  edge(int t, int c) {
    to = t, cost = c;
  }
};

vector<edge>  G[100000];
int d[100000];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int v, e, r, s, t, w;
  cin >> v >> e >> r;
  fill(d, d + v, INF);
  d[r] = 0;
  rep(i, 0, e) {
    cin >> s >> t >> w;
    G[s].push_back(edge(t, w));
  }
  min_priority_queue<P> q;
  q.push({ 0, r });

  while (!q.empty()) {
    P p = q.top(); q.pop();
    int x = p.sd;
    if (d[x] < p.first) continue;
    for (int i = 0; i < G[x].size(); i++) {
      if (d[G[x][i].to] > d[x] + G[x][i].cost) {
        d[G[x][i].to] = d[x] + G[x][i].cost;
        q.push({ d[G[x][i].to], G[x][i].to });
      }
    }
  }
  rep(i, 0, v) {
    if (d[i] == INF)
      cout << "INF" << endl;
    else
      cout << d[i] << endl;
  }

  return 0;
}