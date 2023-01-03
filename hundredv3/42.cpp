#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < n; ++i)
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  vector<int> c(m);
  rep(i, m) cin >> c[i];

  vector dp(n + 1, vector<int>(m + 1, INF));
  rep(i, m + 1) dp[0][i] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; ++j)
    {
      dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + d[i - 1] * c[j - 1]);
      cout << dp[i][j] << " \n"[j == m];
    }
  }
  cout << dp[n][m] << endl;
}