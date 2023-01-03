#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

signed main() {
	int	N;
	cin >> N;
	V	p(N), q(N), ord(N);
	rep(i, 0, N)
		cin >> p[i];
	rep(i, 0, N)
		cin >> q[i];
	rep(i, 0, N)
		ord[i] = i + 1;
	int	a = 0, b = 0, A = 0, B = 0;
	do {
		a++, b++;
		int	i;
		bool	oka = true, okb = true;
		for (i = 0; i < N; i++) {
			if (ord[i] != p[i])
				oka = false;
			if (ord[i] != q[i])
				okb = false;
		}
		if (oka)
			A = a;
		if (okb)
			B = b;
	} while (next_permutation(ord.begin(), ord.end()) && (!A || !B));

	cout << abs(A - B) << endl;
	return 0;
}