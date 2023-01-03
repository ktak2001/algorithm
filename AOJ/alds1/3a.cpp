#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
stack <int> st;
int	solve(string);

int	main()
{
	string	str;
	
	while (cin >> str)
	{
		if (str == "+" || str == "-" || str == "*")
			st.push(solve(str));
		else
			st.push(atoi(str.c_str()));
		if (getchar() == '\n') {// getchar: returns the next character from the standard input.
			cout << st.top() << endl;
			return 0;
		}
	}
}

int	solve(string str)
{
	int	b = st.top();
		st.pop();
	int	a = st.top();
		st.pop();
	if (str == "+")
		return a + b;
	else if (str == "-")
		return a - b;
	else
		return a * b;
}