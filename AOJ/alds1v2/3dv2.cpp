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

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string  str;
  getline(cin, str);
  stack<int>  tmp;
  stack<P>  L;
  stack<int>  finalL;
  int sumAreas = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '/' and !tmp.empty()) {
      int tx = tmp.top(); tmp.pop();
      int sum = i - tx;
      while (!L.empty()) {
        auto [lx, la] = L.top();
        if (lx < tx) break ;
        sum += la;
        L.pop();
      }
      L.push({ tx, sum });
    } else if (str[i] == '\\') {
      tmp.push(i);
    }
  }
  while (!L.empty()) {
    auto [x, area] = L.top(); L.pop();
    finalL.push(area);
    sumAreas += area;
  }
  cout << sumAreas << endl;
  cout << finalL.size();
  while (!finalL.empty()) {
    int a = finalL.top(); finalL.pop();
    cout << " " << a;
  }
  cout << endl;
  return 0;
}