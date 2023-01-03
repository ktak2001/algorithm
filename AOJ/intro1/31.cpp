#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int	main()
{
	int		num[26] = {};
	char	c = 'a';
	while (1)
	{
		string	str;
		cin >> str;

		if (!str.size())
			break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				num[str[i] - 'a']++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				num[str[i] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++)
		printf("%c : %d\n", c + num[i], num[i]);
	return 0;
}