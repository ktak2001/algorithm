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

struct  UnionFind {
  vector<int> road;
  vector<int> rank;

  UnionFind(int N): road(N), rank(N) {
    rep(i, 0, N) road[i] = i, rank[i] = 0;
  }

  int root(int x) {
    if (road[x] == x)
      return x;
    return road[x] = root(road[x]);
  }

  void  unite(int x, int y) {
    int rx = root(x), ry = root(ry);
    if (rx == ry) return;
    if (rank[rx] < rank[ry]) road[rx] = ry;
    else {
      road[ry] = rx;
      if (rank[rx] == rank[ry]) rank[rx]++;
    }
  }

  bool check(int x, int y) {
    return root(x) == root(y);
  }
};

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, q, d, x, y;
  cin >> n >> q;
  UnionFind u(n);
  rep(i, 0, q) {
    cin >> d >> x >> y;
    if (d) u.unite(x, y);
    else cout << (u.check(x, y) ? "Yes" : "No") << endl;
  }

  return 0;
}