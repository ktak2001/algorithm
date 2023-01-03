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

int k, n, x, y, g[50001], eat[50001], eaten[50001], t;

void init() {
  rep(i, 1, n + 1) g[i] = i;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> k >> n;
  init();
  rep(i, 0, k) {
    cin >> t >> x >> y;
    if (t == 1) {
      if (!g[x] and !g[y]) {
        if (!eat[x] or !eat[y] and !eaten[x] or !eaten[y]) {

        }
      }

    }
  }

}