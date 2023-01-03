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

int ans;
int d[100001][100001];

int rec(int num1, int num2, int depth) {
  if (depth == 3)
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m, a, b;
  cin >> n >> m;
  rep(i, 0, m) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    d[a][b] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; i <= n; j++) {
      if (!d[i][j]) {
        d[i][j] = rec(i, j, 1);
      }
    }
  }
}