#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
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

int	m[10][31];

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 10; i++) {
		cout << i << ": " << endl;
		for (int j = 0; j < 10; j++) {
			memset(m[j], i, 30);
			cout << j << ": " << endl;
			for (int k = 0; k < 31; k++) {
				cout << m[j][k] << " \n"[k == 30];
			}
		}
	}
	return 0;
}