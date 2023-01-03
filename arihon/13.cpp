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


V a(10000), d(10000);

int rec(int bts) {

}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m, x, l;
  cin >> n >> m >> x >> l;
  rep(i, 0, n) cin >> a[i];

}

// T mod M == Lとなるようにすればよい / T <= X * M;