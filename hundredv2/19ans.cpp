#ifndef TEMPLATE_TKOYASAK

#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
using namespace std;

#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define sz(obj) (int)(obj).size()
#define YesNo(bool)            \
	if (bool)                  \
	{                          \
		cout << "Yes" << endl; \
	}                          \
	else                       \
	{                          \
		cout << "No" << endl;  \
	}
#define reps(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, a, n) for (int i = (a); i >= (int)(n); --i)
#define fore(i, a) for (auto &i : (a))
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return (true);
	}
	return (false);
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return (true);
	}
	return (false);
}

using ll = long long;
using ull = unsigned long long;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vs = vector<string>;
using vvs = vector<vs>;
using vvvs = vector<vvs>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using pdd = pair<double, double>;
using vpdd = vector<pdd>;

#endif

const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int inf = 1e9 + 10;
// const int mod=1e9+7;
const int mod = 998244353;
const long long INF = 1e18;
const long double EPS = 1e-10;

int main(void)
{
	/* ---------- ---------- ---------- */
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	/* ---------- ---------- ---------- */

	int len, n, m;
	cin >> len >> n >> m;
	vi d(n);
	d[0] = 0;
	rep(i, n - 1) cin >> d[i + 1];
	vi t(m);
	rep(i, m) cin >> t[i];
	ll ans = 0;

	sort(all(d));
	d.emplace_back(len);
	rep(i, m)
	{
		auto it = upper_bound(all(d), t[i]);
		int add = abs(t[i] - *it);
		it--;
		add = min(add, abs(t[i] - *it));
		ans += add;
	}

	cout << ans << endl;
}
