#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	p.push_back(0);
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	n = p.size();
	vector<int> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			q.push_back(p[i] + p[j]);
		}
	}
	sort(q.begin(), q.end());
	q.erase(unique(q.begin(), q.end()), q.end());
	int x = q.size();
	int r = x - 1, ans = 0;
	for (int l = 0; l < x; l++)
	{
		while (l <= r && q[l] + q[r] > m)
			r--;
		if (l > r)
			break;
		ans = max(ans, q[l] + q[r]);
	}
	cout << ans << '\n';
}