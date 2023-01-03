#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <regex>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main()
{
	int n, r[100], c[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> r[i] >> c[i];
	int dp[100][101] = {};
	for (int w = 2; w <= n; w++)
	{
		for (int i = 0; i + w <= n; i++)
		{
			dp[i][i + w] = mod;
			for (int k = i + 1; k < i + w; k++)
				dp[i][i + w] = min(dp[i][i + w], dp[i][k] + dp[k][i + w] + r[i] * r[k] * c[i + w - 1]);
			cout << "j: " << i << " j + i:" << i + w - 1 << " D" << dp[i][i + w] << endl;
		}
	}
	cout << dp[0][n] << endl;
}