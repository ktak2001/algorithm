#include <bits/stdc++.h>
using namespace std;
#define int long long
int	sum = 0;
stack<int>	State;
stack<pair<int, int>>	Lake;
vector<int>	fans;

void	ft_cout() {
	cout << sum << endl;
	cout << Lake.size() << " ";
	for (int i = 0; i < Lake.size(); i++) {
		fans.push_back(Lake.top().second);
		Lake.pop();
	}
	for (auto i = fans.begin(); i != fans.end(); i++)
		cout << *i << " \n"[i + 1 == fans.end()];
}

signed main () {
	string	str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '\\') {
			State.push(i);
		} else if (str[i] == '/') {
			int	s = State.top();
			State.pop();
			int	a = i - s;
			sum += a;
			if (Lake.size() && Lake.top().first > s) {
				a += Lake.top().second;
				Lake.pop();
			}
			Lake.push(make_pair(s, a));
		}
	}
	ft_cout();

	return 0;
}