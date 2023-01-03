#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return 1;
	}
	return 0;
}

int main()
{
	int r, c;
	cin >> r >> c;
	vector<bitset<10>> m(c, 0);

	rep(i, r) rep(j, c)
	{
		int a;
		cin >> a;
		if (a)
			m[j].set(i);// iビット目をtrueにする
	}

	int ans = 0;
	for (int bit = 0; bit < 1 << r; bit++)
	{
		int cnt = 0;
		rep(j, c)
		{
			bitset<10> cp = m[j] ^ (bitset<10>)(bit);
			cnt += max(cp.count(), r - cp.count());
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}