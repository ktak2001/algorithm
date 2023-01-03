#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main()
{
  string s;
  cin >> s;
  int ln = s.length();
  ll ans = 0;
  for (int i = 0; i < (1 << ln); ++i)
  {
    ll sum = 0;
    for (int j = 0; j < ln; ++j)
    {
      if ((i >> j) & 1)
      {
        sum *= 10;
        sum += (s[j] - '0');
      }
      else
      {
        // sum+=(s[j]-'0');
        ans += sum;
        sum = 0;
      }
    }
    ans += sum;
  }
  cout << ans;
  return 0;
}