#include <iostream>
#include <algorithm>
#define int long long
struct	Card {
	char suit;
	int value;
};
using namespace std;

void	bubble(Card A[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (A[j].value < A[j - 1].value) {
				Card	tmp;
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
			}
		}
	}
}

void	selection(Card A[], int n)
{
	for (int i = 0; i < n; i++) {
		int	minj = i;
		for (int j = i; j < n; j++) {
			if (A[j].value < A[minj].value)
				minj = j;
		}
		swap(A[i], A[minj]);
	}
}

void	printing(Card A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i].suit << A[i].value << " \n"[i == n - 1];
}

bool	isStable(Card A[], Card B[], int n)
{
	for (int i = 0; i < n; i++) {
		if (A[i].suit != B[i].suit)
			return false;
	}
	return true;
}

signed	main()
{
	int	n;
	cin >> n;
	Card	C1[n], C2[n];
	for (int i = 0; i < n; i++)
		cin >> C1[i].suit >> C1[i].value;
	for (int i = 0; i < n; i++)
		C2[i] = C1[i];
	bubble(C1, n);
	selection(C2, n);
	printing(C1, n);
	cout << "Stable" << endl;
	printing(C2, n);
	cout << (isStable(C1, C2, n) ? "Stable" : "Not stable") << endl;
	return 0;
}