#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
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

V d(10001, INF);

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, K, A, a[101];
  cin >> n >> K;
  rep(i, 0, n) cin >> a[i];
  cin >> A;
  d[A] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= A - a[i]; j++)
    {
      d[j] = min(d[j], d[j + a[i]] + 1);
    }
  }
  cout << (d[0] == INF ? -1 : d[0]) << endl;

  return 0;
}