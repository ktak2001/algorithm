#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
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

signed main()
{
  string s1, s2;
  V idx;
  getline(cin, s1), getline(cin, s2);
  cout << s1.size() << endl; // 2
  cout << s2.size() << endl; // 3
  cout << s1.size() - s2.size() << endl;
  for (int i = 0; i <= -1; i++)
  {
    cout << "inside" << endl;
  }
  // for (int i = 0; i <= s1.size() - s2.size(); i++)
  // {
  //   cout << "infinite loop" << endl;
  // }


  return 0;
}