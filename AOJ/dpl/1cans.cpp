#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int main()
{
	int n, W, v[100], w[100];
	cin >> n >> W;
	for (int i = 0; i < n; i++)
		cin >> v[i] >> w[i];
	for (int i = 0; i < n; i++)
		for (int j = w[i]; j <= W; j++)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[W] << endl;
}
