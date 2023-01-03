#include <iostream>
#include <string>
using namespace std;

int	main()
{
	while (1)
	{
		int		num = 0;
		string	str;

		getline(cin, str);
		if (str.size() == 1 && str[0] == '0')
			return 0;
		for (int i = 0; i < str.size(); i++)
			num += str[i] - 48;
		cout << num << endl;
	}
}