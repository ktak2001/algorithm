#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
  {
    int q, w;
    cin >> q >> w;
    v.push_back({q - w, q + w});
  }
  sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b)
      { return a.second < b.second; });
  int ans = 1;
  int r = v[0].second;
  for (int i = 1; i < n; i++)
  {
    if (v[i].first >= r)
    {
      r = v[i].second;
      ans++;
    }
  }
  cout << ans;
  return 0;
}