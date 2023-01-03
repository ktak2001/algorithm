#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define ALL(a) (a).begin(), (a).end()
template <class t, class u>
void chmax(t &a, u b) {
	if (a < b)
		a = b;
}
template <class t, class u>
void chmin(t &a, u b) {
	if (b < a)
		a = b;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	int l = 1LL << 60;
	int r = 0;
	vc<int> h(n), s(n);
	rep(i, n) cin >> h[i] >> s[i];
	rep(i, n) {
		chmin(l, h[i]);
		chmax(r, h[i] + (n - 1) * s[i]);
	}
	r++;
	while (r - l > 1)
	{
		int mid = (r + l) / 2;
		bool f = true;
		vc<int> cnt(n + 1, 0);
		for (int i = 0; i < n; i++) {
			if (mid < h[i]) {
				f = false;
			}
			else {
				int x = 1 + (mid - h[i]) / s[i];// midにたどり着くまでにかかる時間
				cnt[min(n, x)]++; //n秒以上かかっている場合、そのタイミングはいつでもよい
			}
		}
		for (int i = 1; i <= n; i++) {
			cnt[i] += cnt[i - 1];
			if (cnt[i] > i)// 例えばmidにたどり着くまでにかかる時間が7秒の風船が8個以上の場合、満たせない。
				f = false;
		}
		if (f)
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}