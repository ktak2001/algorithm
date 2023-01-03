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
  string  str;
  getline(cin, str);
  int s[17], sum = 0;
  rep(i, 0, str.size()) s[i] = str[i] - '0';
  // rep(i, 0, str.size()) cout << s[i] << " \n"[i == str.size() - 1];
  for (int i = 0; i < 1 << (str.size() - 1); i++) {
    int         a = 0;
    queue<int>  A;
    A.push(s[0]);
    for (int j = str.size() - 2; j >= -1; j--) {
      if (j == -1 || (1 << j & i))
      {
        int t = 0;
        while (!A.empty()) {
          int tmp = A.front();
          A.pop();
          t *= 10;
          t += tmp;
        }
        a += t;
        if (j == -1)
          break ;
      }
      A.push(s[str.size() - j - 1]);
    }
    sum += a;
  }
  cout << sum << endl;
  return 0;
}