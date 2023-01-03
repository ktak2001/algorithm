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

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int N, L, p, pos = 0, a[10000], b[10000], d, ans = 0;
  priority_queue<int> q;
  cin >> N >> L >> p;
  for (int i = 0; i < N; i++) {
    d = a[i] - pos;
    while (p < d) {
      if (q.empty()) {
        ans = -1;
        i += N;
        break;
      } else {
        p+= q.top();
        q.pop();
        ans++;
      }
    }
    p -= d;
    pos = a[i];
    q.push(b[i]);
  }
  cout << ans << endl;
  return 0;
}