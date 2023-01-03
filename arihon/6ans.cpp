#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, m, n) for (ll i = m; i < (ll)n; i++)
#define ALL(v) v.begin(), v.end()
#define P pair<ll, ll>
#define MP make_pair
const ll INF = 9e18;

int main()
{
  string S, T;
  cin >> S >> T;
  ll chg = -1;
  rep(i, 0, S.size() - T.size() + 1)
  {
    rep(j, 0, T.size())
    {
      if (i + j >= S.size() || (S[i + j] != '?' && S[i + j] != T[j]))
      {
        break;
      }
      if (j == T.size() - 1)
      {
        chg = i;
      }
    }
  }
  if (chg == -1)
  {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  rep(i, 0, S.size())
  {
    if (chg <= i && i < chg + T.size())
      cout << T[i - chg];
    else if (S[i] == '?')
      cout << "a";
    else
      cout << S[i];
  }
  cout << endl;
  return 0;
}