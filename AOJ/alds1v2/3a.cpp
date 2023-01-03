#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
using V = vector<int>;
using VV = vector<V>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }

stack<int>	S;

void	calc(char op) {
	int	b = S.top();
	S.pop();
	int	a = S.top();
	S.pop();
	switch(op) {
		case '+':
			S.push(a + b);
			break ;
		case '-':
			S.push(a - b);
			break ;
		case '*':
			S.push(a * b);
			break ;
		case '/':
			S.push(a / b);
			break;
	}
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string	str;
	while (cin >> str) {
		if (str == "+" || str == "-" || str == "*" || str == "/") {
			calc(str[0]);
		} else {
			S.push(atoi(str.c_str()));
		}
		if (getchar() == '/n') {
			return 0;
		}
	}
}