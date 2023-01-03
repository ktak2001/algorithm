#include <iostream>
#include <cstdio>
using namespace std;

int	main()
{
	int		n, irank;
	int		cards[4][13] = {};
	int		isuit;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> isuit >> irank;
		switch (isuit)
		{
			case 'S':
				cards[0][irank - 1]++;
				break;
			case 'H':
				cards[1][irank - 1]++;
				break;
			case 'C':
				cards[2][irank - 1]++;
				break;
			case 'D':
				cards[3][irank - 1]++;
				break;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (!cards[i][j]) {
				switch (i)
				{
					case 0:
						cout << "S" << " " << j + 1 << endl;
						break;
					case 1:
						cout << "H" << " " << j + 1 << endl;
						break;
					case 2:
						cout << "C" << " " << j + 1 << endl;
						break;
					case 3:
						cout << "D" << " " << j + 1 << endl;
						break;
				}
			}
		}
	}
	return 0;
}