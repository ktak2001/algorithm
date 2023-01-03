#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define max(a, b) ((a) >= (b) ? (a) : (b))
using P = pair<int, int>;
int	n, mx = 0;

signed main() {
	cin >> n;
	P	N[n];
	rep(i, 0, n)
		cin >> N[i].ft >> N[i].sd;
	rep(i, 0, n - 3) {
		rep(j, i + 1, n - 2) {
			int	a = N[i].ft - N[j].ft;
			int	b = N[i].sd - N[j].sd;
			int	szX = a * a;
			int	szY = b * b;
			int	sz = szX + szY;
			if (sz <= mx)
				continue ;
			
		}
	}
}