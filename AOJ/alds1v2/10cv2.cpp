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

int dp[1001][1001];
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int q, ans[150];
  string  s1, s2;

  cin >> q;
  rep(i, 0, q) {
    cin >> s1 >> s2;
    for (int j = 0; j <= s1.size(); j++) {
      for (int k = 0; k <= s2.size(); k++) {
        if (!j or !k) dp[j][k] = 0;
        else if (s1[j - 1] == s2[k - 1])
          dp[j][k] = dp[j - 1][k - 1] + 1;
        else
          dp[j][k] = max(dp[j - 1][k], dp[j][k - 1]);
      }
    }
    ans[i] = dp[s1.size()][s2.size()];
  }
  rep(i, 0, q) cout << ans[i] << endl;

  return 0;
}