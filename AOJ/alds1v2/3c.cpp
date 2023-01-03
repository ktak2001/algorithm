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

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int			N;
	list<int>	L;
	cin >> N;
	rep(i, 0, N) {
		string	str;
		int	a;
		cin >> str;
		if (str.size() > 6) {
			if (str[6] == 'F') {
				L.pop_front();
			} else {
				L.pop_back();
			}
		} else {
			cin >> a;
			if (str[0] == 'i') {
				L.push_front(a);
			} else {
				for (auto itr = L.begin(); itr != L.end(); ++itr) {
					if (a == *itr) {
						L.erase(itr);
						break ;
					}
				}
			}
		}
	}
	for (auto itr = L.begin(); itr != L.end();) {
		cout << *itr << " \n"[++itr == L.end()];
	}
	return 0;
}