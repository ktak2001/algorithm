#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long>> vvll, vvLL;

#define VV(T) vector<vector<T>>

template <class T>
void initvv(vector<vector<T>> &v, int a, int b, const T &t = T())
{
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t)
{
	stringstream ss;
	ss << f;
	ss >> t;
}

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define PB push_back

#define MOD 1000000009LL
#define EPS 1e-8

int main()
{
	bool con[15][15] = {};
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		con[x - 1][y - 1] = con[y - 1][x - 1] = true;
	}

	int ans = 0;
	for (int S = 1 << n; --S;)
	{
		int t = bitset<32>(S).count();// 1の数
		if (t <= ans)
			continue;
		bool ok = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
			{
				if (S >> i & S >> j & 1 && !con[i][j])
				{
					ok = false;
				}
			}
		if (ok)
		{
			ans = t;
		}
	}
	cout << ans << endl;
}
