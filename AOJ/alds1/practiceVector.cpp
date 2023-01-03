#include <vector>
#include <iostream>
using namespace std;

int	main()
{
	vector <int> k(1, 0);// 要素数、初期値
	vector <vector<int>> vv{{1, 2, 3}, {4, 5, 6}};
	vector <char> str;
	vector <char> a(10, 'a');
	vector <double> d{1.1, 2.2, 3.3, 4.4};

	int	ar[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int>	v{9, 8, 7};
	v.assign(&ar[0], &ar[3]);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}