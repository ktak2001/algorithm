#include <iostream>
#include <cstring>
using namespace std;

int	main()
{
	string	str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	}
	cout << str << endl;
	return 0;
}