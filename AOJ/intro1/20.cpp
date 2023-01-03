#include <iostream>
using namespace std;

int	main()
{
	int	i, n;
	cin >> n;

	i = 0;
	while (++i <= n)
	{
		if (!(i % 3) || i % 10 == 3)
			cout << " " << i;
		else {
			int	x = i;
			x /= 10;
			while (x)
			{
				if (x % 10 == 3)
				{
					cout << " " << i;
					break;
				}
				x /= 10;
			}
		}
	}
	cout << endl;
}

// void call(int n){
// 	int i = 1;
// 	CHECK_NUM:
// 	int x = i;
// 	if ( x % 3 == 0 ){
// 		cout << " " << i;
// 		goto END_CHECK_NUM;
// 	}
// 	INCLUDE3:
// 	if ( x % 10 == 3 ){
// 		cout << " " << i;
// 		goto END_CHECK_NUM;
// 	}
// 	x /= 10;
// 	if ( x ) goto INCLUDE3;
// 	END_CHECK_NUM:
// 	if ( ++i <= n ) goto CHECK_NUM;

// 	cout << endl;
// }