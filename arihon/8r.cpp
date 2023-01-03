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

int n, a[50001], c[50000], sum = 0;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  list<int>   l(n);
  for (auto itr = l.begin(); itr != l.end(); itr++) {
    cin >> *itr;
  }
  l.sort();
  while (l.size() >= 2) {
    for (auto itr: l) cout << itr;
    cout << endl;
    auto itr = l.begin();
    int newX = *itr++;
    newX += *itr;
    sum += newX;
    l.insert(lower_bound(l.begin(), l.end(), newX), newX);
    l.pop_front();
    l.pop_front();
  }
  cout << sum << endl;

  return 0;
}