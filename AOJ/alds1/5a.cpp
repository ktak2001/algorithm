#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define MAX 2000
int	n, q, v;
vector<int>	V;

bool	Check(int id, int dif) {
	if (!dif)
		return 1;
	if (id == n || dif < 0)
		return 0;
	return Check(id + 1, dif) || Check(id + 1, dif - V[id]);
}

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		V.push_back(v);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> v;
		cout << (Check(0, v) ? "yes" : "no") << endl;
	}

	return 0;
}