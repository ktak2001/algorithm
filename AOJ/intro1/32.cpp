#include <iostream>
#include <string>
using namespace std;

int	main()
{
	string	str;
	int		alpha[26] = {};

	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				alpha[str[i] - 'a']++;
			if (str[i] >= 'A' && str[i] <= 'Z')
				alpha[str[i] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << (char)('a' + i) << " : " << alpha[i] <<  endl;
	}
	return 0;
}