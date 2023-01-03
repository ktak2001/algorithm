#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
using T = tuple<int, int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define mt make_tuple
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

int	m, n;

typedef struct	pp {
	int	height;
	int	i1;
	int	i2;
	int	num;
	pp () {}
	pp (int height, int i1, int i2, int num) : height(height), i1(i1), i2(i2), num(num) {};
} p;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	V	ice[m];
	V	A;
	vector<p>	lineP;
	int	x, k = 0;
	rep(i, 0, m) {
		bool	ok = 1;
		rep(j, 0, n) {
			cin >> x;
			if (x) {
				if (lineP.back().height == i) {
					if (lineP.back().i2 == j - 1)
						lineP[lineP.size() - 1].i2++;
					else {
						lineP.push_back()
					}
				}
			}
			ice[i].push_back(x);
		}
	}


}