#include <bits/stdc++.h>
using namespace std;
#define int long long

struct	Coprime {
	vector<int>	r, p;
	Coprime() {};
	Coprime(int size) {
		r.resize(size, 0);
		p.resize(size, 0);
		for (int i = 0; i < size; i++)
			r[i] = 1, p[i] = i;
	};

	void	unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return ;
		if (r[x] < r[y])
			swap(x, y);
		if (r[x] == r[y])
			r[x]++;
		p[y] = x;
	};

	int	same(int x, int y) {
		return find(x) == find(y);
	};

	int	find(int x) {
		return p[x] == x ? x : find(p[x]);
	}
} ;

signed main () {
	int	n, q, x, y, c;
	cin >> n >> q;
	Coprime	cp(n);
	for (int i = 0; i < q; i++) {
		cin >> c >> x >> y;
		if (c)
			cout << cp.same(x, y) << endl;
		else
			cp.unite(x, y);
	}
	return 0;
}