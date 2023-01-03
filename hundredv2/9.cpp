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

int	n, m;

P	signs(vector<P>	M, vector<P> N) {
	int	a = M[0].ft, b = M[0].sd;
	rep(i, 0, n - m + 1) {
		int	s = N[i].ft - a, t = N[i].sd - b;
		auto	bgn = N.begin() + i + 1;
		bool	T = 1;
		rep(j, 1, m) {
			auto	itr = find(bgn, N.end(), mp(s + M[j].ft, t + M[j].sd));
			if (itr == N.end() and j + 1 < m) {
				T = 0;
				break ;
			}
			bgn = itr + 1;
			// cout << i << " " << j << endl;
		}
		if (T)
			return (mp(s, t));
	}
	return (mp(0, 0));
}

void	NlogN(vector<P>	M[], int l, int mid, int r, bool T) {
	int	a = mid - l, b = r - mid;
	vector<P>	A(a + 1), B(b + 1);
	rep(i, 0, a)
		A[i] = (*M)[l + i];
	rep(i, 0, b)
		B[i] = (*M)[mid + i];
	A[a].ft = A[a].sd = INT_MAX;
	B[b].ft = B[b].sd = INT_MAX;
	int	j = 0, k = 0;
	rep(i, l, r) {
		if ((A[j].ft < B[k].ft))
			(*M)[i] = A[j++];
		else if (A[j].ft == B[k].ft) {
			(*M)[i] = (A[j].sd < B[k].sd ? A[j++] : B[k++]);
		}
		else
			(*M)[i] = B[k++];
	}
}

void	srt(vector<P>	M[], int l, int r, bool T) {
	if (l + 1 >= r)
		return ;
	int	mid = (l + r) / 2;
	srt(M, l, mid, T);
	srt(M, mid, r, T);
	NlogN(M, l, mid, r, T);
}

signed main() {
	cin >> m;
	vector<P>	M(m);
	rep(i, 0, m)
		cin >> M[i].ft >> M[i].sd;
	srt(&M, 0, m, 0);
	cin >> n;
	vector<P>	N(n);
	rep(i, 0, n)
		cin >> N[i].ft >> N[i].sd;
	srt(&N, 0, n, 0);
	// cout << "M:" << endl;
	// rep(i, 0, m)
	// 	cout << M[i].ft << " " << M[i].sd << endl;
	// cout << "N:" << endl;
	// rep(i, 0, n)
	// 	cout << N[i].ft << " " << N[i].sd << endl;
	auto	[X, Y] = signs(M, N);
	cout << X << " " << Y << endl;

	return 0;
}