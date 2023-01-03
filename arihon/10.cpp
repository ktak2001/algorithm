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

int n, d[1001][1001], ans[150];
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string  s1, s2;
  cin >> n;
  rep(i, 0, n) {
    cin >> s1 >> s2;
    for (int j = 1; j <= s1.size(); j++)
      for (int k = 1; k <= s2.size(); k++) {
        if (s1[j - 1] == s2[k - 1])
          d[j][k] = d[j - 1][k - 1] + 1;
        else
          d[j][k] = max(d[j - 1][k], d[j][k - 1]);
      }
    ans[i] = d[s1.size()][s2.size()];
  }
  rep(i, 0, n) cout << ans[i] << endl;

  return 0;
}