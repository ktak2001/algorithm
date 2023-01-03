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

stack<P >	L;
stack<int>	T;
stack<P >	Pos;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	char	a;
	int	 i = 0;
	list<int>	A;
	L.push(P(200, 0));
	while (true) {
		cin >> a;
		if (a == '1') {
			break ;
		}
		if (a == '\\') {
			T.push(i);
		} else if (a == '/') {
			if (T.size()) {
				int	f = T.top();
				T.pop();
				int	a = i - f;
				while (L.size() and L.top().first > f) {
					a += L.top().second;
					L.pop();
				}
				L.push(P(f, a));
			}
		}
		i++;
		cout << "area" << L.top().second << endl;
		cout << "index" << i << endl;
		// if (getchar() == '\n') {
		// 	break ;
		// }
	}
	cout << L.size() << endl;
	while (!L.empty()) {
		A.push_front(L.top().second);
		L.pop();
	}
	for (auto itr = A.begin(); itr != A.end(); ) {
		cout << *itr << " \n"[++itr == A.end()];
	}
	return 0;
}