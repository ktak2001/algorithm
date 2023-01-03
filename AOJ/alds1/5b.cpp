#include <bits/stdc++.h>
using namespace std;
#define int long long
int	n, sum = 0;

void	Merge(int A[], int l, int mid, int r) {
	int	L[mid - l + 1];
	int	R[r - mid + 1];

	for (int i = l; i < mid; i++)
		L[i - l] = A[i];
	for (int i = mid; i < r; i++)
		R[i - mid] = A[i];
	L[mid - l] = INT_MAX;
	R[r - mid] = INT_MAX;
	int	j = 0, k = 0;
	for (int i = l; i < r; i++) {
		if (L[j] <= R[k]) {
			A[i] = L[j++];
		} else {
			A[i] = R[k++];
			sum += mid - l - j;
		}
	}
}

void	MergeSort(int A[], int l, int r) {
	int	mid = (r + l + 1) / 2;
	if (l + 1 < r) {
		MergeSort(A, l, mid);
		MergeSort(A, mid, r);
		Merge(A, l, mid, r);
	}
	return ;
}

signed main() {
	cin >> n;
	int	A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	MergeSort(A, 0, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " \n"[i + 1 == n];
	return 0;
}