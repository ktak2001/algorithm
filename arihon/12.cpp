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

int n, W, v[200], w[200], maxV, maxW;

int rec(int i, int posb) {
  if (i == n) {
    return 0;
  }
  if (posb < w[i]) {
    return rec(i + 1, posb);
  } else {
    return max(rec(i + 1, posb), rec(i + 1, posb - w[i]) + v[i]);
  }
  return 0;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> W;
  rep(i, 0, n) {
    cin >> v[i] >> w[i];
    maxV = max(maxV, v[i]), maxW = max(maxW, w[i]);
  }
  V d;
  if (maxW <= 1000) {
    d.assign(W + 1, 0);
    rep(i, 0, n) {
      for (int j = W; j >= w[i]; j--) {
        d[j] = max(d[j], d[j - w[i]] + v[i]);
      }
    }
    cout << d[W] << endl;
  } else if (maxV <= 1000) {
    d.assign(n * maxV + 1, INF);
    d[0] = 0;
    rep(i, 0, n) {
      for (int j = n * maxV; j >= v[i]; j--) {
        d[j] = min(d[j], d[j - v[i]] + w[i]);
      }
    }
    for (auto itr = d.rbegin(); itr != d.rend(); itr++) {
      if (*itr <= W) {
        cout << distance(d.begin(), (itr + 1).base()) << endl;
        return 0;
      }
    }
  } else {
    cout << rec(0, W) << endl;
  }

  return 0;
}