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

int n, A;
bool d[2][10001];

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  V   a(101);
  cin >> n;
  rep(i, 1, n + 1) cin >> a[i];
  cin >> A;
  d[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = A; j >= 0; j--) {
      d[i % 2][j] = d[(i - 1) % 2][j];
      if (j >= a[i]) d[i % 2][j] |= d[(i - 1) % 2][j - a[i]];
    }
  }
  rep(i, 0, A + 1) cout << d[n % 2][i] << endl;

  return 0;
}