#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
using P = pair<int, int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

int	n, ans = 0;
vector<int>	A;
vector<int>	B;
void	srt() {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	rep(i, 0, n){
		ans += i > n / 2 ? A[i] - A[n / 2] : A[n / 2] - A[i];
		ans += i > n / 2 ? B[i] - B[n / 2] : B[n / 2] - B[i];
	}
}

signed main() {
	cin >> n;
	A.assign(n, 0);
	B.assign(n, 0);
	rep(i, 0, n) {
		cin >> A[i] >> B[i];
		ans += B[i] - A[i];
	}
	srt();
	cout << ans << endl;

	return 0;
}