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
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }
const int INF = 1LL << 55LL;

V	N(500001);
int	n;

void	merge(int l, int m, int r) {
	V	a(m - l + 1);
	V	b(r - m + 1);
	a[m - l] = b[r - m] = INF;
	rep(i, l, m) a[i - l] = N[i];
	rep(i, m, r) b[i - m] = N[i];
	int	j = 0, k = 0;
	rep(i, l, r) {
		if (a[j] <= b[k]) {
			N[i] = a[j++];
		} else {
			N[i] = b[k++];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << N[i] << " \n"[i + 1 == n];
	}
}

void	mSort(int l, int r) {
	if (r - l <= 1) {
		return ;
	}
	int	mid = (l + r) / 2;
	mSort(l, mid), mSort(mid, r);
	merge(l, mid, r);
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	rep(i, 0, n) cin >> N[i];
	mSort(0, n);
	for (int i = 0; i < n; i++) {
		cout << N[i] << " \n"[i + 1 == n];
	}
	return 0;
}