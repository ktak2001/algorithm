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
  string  S;
  getline(cin, S);
  char  s[100];
  rep(i, 0, S.size()) s[i] = S[i];
  int l = 0, r = S.size();
  for (; l < r;) {
    if (s[l] < s[r - 1]) {
      cout << s[l++];
    } else {
      cout << s[r-- - 1];
    }
  }
  cout << endl;
  return 0;
}