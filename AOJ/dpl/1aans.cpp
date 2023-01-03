#include <iostream>
#include <algorithm>
using namespace std;
int dp[50001];
int main()
{
	int n, m, c[20];
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> c[i];
	fill(dp + 1, dp + n + 1, 1e9);
	for (int i = 0; i < m; i++)
		for (int j = c[i]; j <= n; j++)
			dp[j] = min(dp[j], dp[j - c[i]] + 1); // 
	cout << dp[n] << endl;
}