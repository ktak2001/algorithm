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

int n, x[100000], l[100000];
multiset<P> M;
bool  operator<(const P &x, const P &y) {
  return x.first < y.first;
}
vector<P> R(100000, mp(INF, 0));

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  int X, sum = 0;
  rep(i, 0, n) {
    cin >> x[i] >> l[i];
    R[i] = mp(x[i] - l[i], i);
  }
  sort(R.begin(), R.begin() + n);
  for (int i = 0; i < n;) {
    X = x[R[i].sd] + l[R[i].sd];
    rep(j, i, n) {
      X = min(X, x[R[j].sd] + l[R[j].sd]);
      if (X <= R[j + 1].ft) {
        i = j + 1;
        break ;
      }
    }
    ++sum;
  }
  cout << sum << endl;

  return 0;
}