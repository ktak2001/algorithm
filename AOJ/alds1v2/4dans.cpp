#include <iostream>
#include <vector>

using namespace std;

bool f(const vector<int> &w, int P, int k)
{
	int i = 0, n = (int)w.size();
	for (int j = 0; j < k; ++j)
	{
		for (int wj = 0; i < n && wj + w[i] < P; ++i)
			wj += w[i];
		if (i >= n)
			return true;
	}
	return i >= n;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> w(n);
	for (auto &wi : w)
		cin >> wi;

	int P = 0;
	for (int dP = 1 << 29; dP > 0; dP /= 2)
		if (!f(w, P + dP, k))
			P += dP;
	cout << P << endl;
	return 0;
}