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

const int maxn = 2e5 + 5;
int n, k, l, fr, to, road[maxn], rail[maxn];

inline void init() {
  rep(i, 1, n + 1) road[i] = rail[i] = i;
}

inline int findRoad(int x) {
  if (road[x] == x) return x;
  return road[x] = findRoad(road[x]);
}
inline int findRail(int x) {
  if (rail[x] == x) return x;
  return rail[x] = findRail(rail[x]);
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  map<P, int> pm;
  cin >> n >> k >> l;
  init();
  rep(i, 0, k) cin >> fr >> to, road[findRoad(fr)] = road[findRoad(to)];
  rep(i, 0, l) cin >> fr >> to, rail[findRail(fr)] = rail[findRail(to)];
  rep(i, 1, n + 1) findRoad(i), findRail(i);
  rep(i, 1, n + 1) pm[{road[i], rail[i]}]++;
  rep(i, 1, n + 1) cout << pm[{road[i], rail[i]}] << " \n"[i == n];

  return 0;
}