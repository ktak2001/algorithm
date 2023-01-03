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

int n, a[2000], d[2000][2000];

int rec(int s, int l) {
  if (d[s][l]) return d[s][l];
  if (l == 0) return d[s][0] = a[s];
  int e;
  e = (s + l > n - 1) ? s + l - n : s + l;
  if (n % 2 != (l + 1) % 2) {
    if (a[s] > a[e]) {
      s = (s == n - 1) ? 0 : s + 1;
    }
    return d[s][l - 1] = rec(s, l - 1);
  } else {
    return d[s][l] = max(a[s] + rec(s + 1, l - 1), a[e] + rec(s, l - 1));
  }
  return 0;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  rep(i, 0, n) cin >> a[i];
  int mx = 0;
  rep(i, 0, n) {
    mx = max(mx, rec(i, n - 1));
  }
  cout << mx << endl;

  return 0;
}