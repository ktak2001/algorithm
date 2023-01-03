#include <iostream>
#include <vector>
using namespace std;

int	main()
{
	int	n, a;

	vector <int> v(1, 0);
	cin >> n;
	while (n--) {
		cin >> a;
		v.push_back(a);
	}
	for (int j = 1; j < v.size(); j++) {
		int	key = v[j], i = j - 1;
		while (i > 0 && v[i] > key) {
			v[i + 1] = v[i];
			i--;
		}
		v[i + 1] = key;
		for (int j = 1; j < v.size(); j++) {
			cout << (j == 1 ? "" : " ") << v[j];
		}
		cout << endl;
	}
	return 0;
}