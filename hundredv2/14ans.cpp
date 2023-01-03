#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	long long ans = INF;
	for (int i = 0; i < (1 << N); ++i) {
		if (__builtin_popcount(i) == K) {// 1が何個あるか
			long long cost = 0;
			long long p = 0;
			for (int j = 0; j < N; ++j) {
				if ((i >> j) & 1) {
					if (A[j] > p)
						p = A[j];
					else
						cost += ++p - A[j];
				}
				else {
					if (A[j] > p) {
						p = A[j];
					}
				}
			}
			ans = min(ans, cost);
		}
	}
	cout << ans << endl;
}
