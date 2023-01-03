#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
vector	<int> G;
int	cnt;
int	A[1000000000];
int	n;

void	shellSort(int g, int A[])
{
	for (int j = g; j < n; j++) {
		for (int s = j - g; s >= 0 && A[s] > A[s + g]; s -= g) {
			swap(A[s], A[s + g]);
			cnt++;
		}
	}
}

signed	main()
{
	int	cnt = 0;
	cin >> n;
	for (int j = 1; j < n; ) {
		G.push_back(j);
		j = j * 3 + 1;
	}
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = G.size() - 1; i >= 0; i--)
		shellSort(G[i], A);
	cout << G.size() << endl;
	for (int i = G.size() - 1; i >= 0; i--)
		cout << G[i] << " \n"[!i];
	for (int i = 0; i < n; i++)
		cout << A[i] << endl;
	return 0;
}
