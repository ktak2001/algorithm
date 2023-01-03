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
  string  s1, s2;
  V       idx;
  getline(cin, s1), getline(cin, s2);
  if (s1.size() < s2.size()) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  for (int i = 0; i <= s1.size() - s2.size(); i++) {
    idx.push_back(i);
    for (int j = 0; j < s2.size(); j++) {
      if (s1[i + j] != s2[j] and s1[i + j] != '?') {
        idx.pop_back();
        break;
      }
    }
  }
  if (idx.empty()) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  for (int i = 0; i < s1.size(); i++) {
    if (i == idx.back()) {
      for (int j = 0; j < s2.size(); j++) {
        s1[i + j] = s2[j];
      }
      i += s2.size() - 1;
    } else if (s1[i] == '?') s1[i] = 'a';
  }
  cout << s1 << endl;

  return 0;

}