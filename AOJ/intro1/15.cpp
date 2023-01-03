#include <iostream>

using namespace std;

int	main()
{
	int		a, b, ans;
	char	op;

	while (1)
	{
		cin >> a >> op >> b;
		switch(op)
		{
			case '+':
				ans = a + b;
				break;
			case '-':
				ans = a - b;
				break;
			case '*':
				ans = a * b;
				break;
			case '/':
				ans = a / b;
				break;
			default:
				return 0;
		}
		cout << ans << endl;
	}
	return 0;
}