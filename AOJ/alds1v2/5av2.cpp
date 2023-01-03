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

const int maxn = 2e21 + 1;
int d[2];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, q, m[200];
  V   A(20);
  cin >> n;
  rep(i, 0, n) cin >> A[i];
  cin >> q;
  for (int i = 0; i < 1 << n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (1 << j & i)
        sum += A[j];
    }
    d[i] = sum;
  }
  sort(d, d + maxn);
  rep(i, 0, q) {
    cin >> m[i];
    cout << (*lower_bound(d, d + maxn, m[i]) == m[i] ? "yes": "no") << endl;
  }

  return 0;
}