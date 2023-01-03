#include <bits/stdc++.h>
using namespace std;

int ret(vector<int> ok, vector<int> a)
{
	int cnt = 1;
	while (ok != a)
	{
		cnt++;
		next_permutation(ok.begin(), ok.end());
	}
	return cnt;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	vector<int> ok(n);
	for (int i = 0; i < n; i++)
		ok[i] = i + 1;

	int ans = abs(ret(ok, a) - ret(ok, b));
	cout << ans << endl;

	return 0;
}