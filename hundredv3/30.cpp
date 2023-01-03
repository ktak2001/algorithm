#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
using V = vector<int>;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
template <class t, class u>
void chmax(t &a, u b)
{
	if (a < b)
		a = b;
}
template <class t, class u>
void chmin(t &a, u b)
{
	if (b < a)
		a = b;
}

int H, W, N, TM = 0, vec[8] = {0, 1, 0, -1, 1, 0, -1, 0};
P S;

void cheese(vector<V> v, vector<P> d)
{
	rep(i, 0, N)
	{
		queue<P> Q;
		Q.push(d[i]);
		vector<V> u(H);
		rep(i, 0, H)
			u[i].assign(W, -1);
		u[d[i].ft][d[i].sd] = 0;
		bool	ok = true;
		while (ok)
		{
			auto [b, a] = Q.front();
			Q.pop();
			for (int j = 0; j < 8; j += 2)
			{
				int s = b + vec[j], t = a + vec[j + 1];
				if (s < 0 || s >= H || t < 0 || t >= W || v[s][t] || u[s][t] >= 0)
					continue;
				u[s][t] = u[b][a] + 1;
				if (d[i + 1].ft == s and d[i + 1].sd == t)
				{
					TM += u[s][t];
					ok = false;
					break;
				}
				Q.push({s, t});
			}
		}
	}
}

signed main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> H >> W >> N;
	char c;
	vector<V> v;
	vector<P> d(N + 1);
	v.resize(H, V(W));
	rep(i, 0, H)
	{
		rep(j, 0, W)
		{
			cin >> c;
			v[i][j] = (c == 'X' ? 1 : 0);
			if (c >= '1' and c <= '9')
				d[c - '0'] = {i, j};
			if (c == 'S')
				d[0] = {i, j};
		}
	}
	cheese(v, d);
	cout << TM << endl;
	return 0;
}