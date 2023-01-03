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

int n, tmp, sum = 0;
V   a, b;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  a.assign(n, 0), b.assign(n + 1, 0);
  rep(i, 0, n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; i--) b[i] = a[i] + b[i + 1];
  rep(i, 0, n) sum += b[i] + a[i];
  sum -= a[n - 1];
  cout << sum << endl;

  return 0;
}