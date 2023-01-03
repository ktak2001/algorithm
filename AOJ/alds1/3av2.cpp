#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

stack <int> s;

int	solve(string str)
{
	int	a = s.top();
	s.pop();
	int	b = s.top();
	s.pop();
	if (str == "+")
		return a + b;
	if (str == "-")
		return a - b;
	else
		return a * b;
}

int	main()
{
	string	str;
	while (cin >> str) {
		if (str == "*" || str == "-" || str == "+")
			s.push(solve(str));
		else
			s.push(atoi(str.c_str()));
		if (getchar() == '\n') {
			cout << s.top() << endl;
			return 0;
		}
	}
}