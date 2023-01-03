#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main()
{

	int n, k;
	cin >> n >> k;

	vector<int> w(n);
	rep(i, n) cin >> w[i];

	int ok = Inf, ng = 0;

	while (ok - ng > 1)
	{
		int mid = (ok + ng) / 2;
		vector<int> t;
		rep(i, n)
		{
			if (t.size() == 0 || t.back() + w[i] > mid)
				t.push_back(w[i]);
			else
				t.back() += w[i];
			if (t.back() > mid)
			{
				while (t.size() <= k)
					t.push_back(0);
				break;
			}
		}
		if (t.size() <= k)
			ok = mid;
		else
			ng = mid;
	}

	cout << ok << endl;
	return 0;
}
