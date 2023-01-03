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

int n, d[1001][1001];

signed main() {
  // cin.tie(0);
  // ios_base::sync_with_stdio(false);
  string  s1, s2;
  cin >> n;
  cout << "n" << n << endl;
  rep (i, 0, n) {
    getline(cin, s1);
    getline(cin, s2);
    // cout << "s1" << s1 << endl;
    rep(j, 0, s1.size() + 1)
      rep (k, 0, s2.size() + 1)
        d[j][k] = 0;
    rep(j, 0, s1.size()) {
      rep(k, 0, s2.size()) {
        if (s1[j] == s2[k]) d[j + 1][k + 1] = d[j][k] + 1;
        else d[j + 1][k + 1] = max(d[j + 1][k], d[j][k + 1]);
      }
    }
    cout << d[s1.size()][s2.size()] << endl;
  }

  return 0;
}