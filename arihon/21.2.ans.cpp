#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n, k, l, fa1[maxn], fa2[maxn];

inline int find1(int x)
{
  if (fa1[x] == x)
    return x;
  return fa1[x] = find1(fa1[x]);
}
inline int find2(int x)
{
  if (fa2[x] == x)
    return x;
  return fa2[x] = find2(fa2[x]);
}

inline void init()
{
  for (int i = 1; i <= n; ++i)
    fa1[i] = fa2[i] = i;
}

map<pair<int, int>, int> F;

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> k >> l;
  init();
  int fo, to;
  for (int i = 1; i <= k; ++i)
  {
    cin >> fo >> to;
    fa1[find1(fo)] = fa1[find1(to)];
  }
  for (int i = 1; i <= l; ++i)
  {
    cin >> fo >> to;
    fa2[find2(fo)] = fa2[find2(to)];
  }
  for (int i = 1; i <= n; ++i)
    find1(i), find2(i);
  for (int i = 1; i <= n; ++i)
    F[{fa1[i], fa2[i]}]++;

  for (int i = 1; i < n; ++i)
    cout << F[{fa1[i], fa2[i]}] << ' ';
  cout << F[{fa1[n], fa2[n]}] << '\n';
  return 0;
}