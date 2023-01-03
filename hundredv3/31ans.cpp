#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <climits>
#include <functional>
#include <cassert>
#include <numeric>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n)-1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mod 1000000007
using namespace std;
template <class T, class U>
bool chmax(T &a, const U &b) { return a < b ? (a = b, 1) : 0; }
template <class T, class U>
bool chmin(T &a, const U &b) { return a > b ? (a = b, 1) : 0; }
int dy[] = {-1, 0, 1, 1, 0, -1};
int dx1[] = {1, 1, 1, 0, -1, 0};
int dx2[] = {0, 1, 0, -1, -1, -1};
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> w >> h;
	vvi a(h + 2, vi(w + 2));
	rep(i, h) rep(j, w) cin >> a[i + 1][j + 1];
	int ans = 0;
	vvi checked(h + 2, vi(w + 2));
	queue<pii> que;
	que.push({0, 0});
	checked[0][0] = 1;
	while (!que.empty())
	{
		int posy = que.front().first;
		int posx = que.front().second;
		que.pop();
		rep(i, 6)
		{
			int y = posy + dy[i];
			int x = posx + ((posy & 1) ? dx1[i] : dx2[i]);
			if (y < 0 || x < 0 || y > h + 1 || x > w + 1)
				continue;
			if (checked[y][x])
				continue;
			if (a[y][x])
			{
				ans++;
				continue;
			}
			checked[y][x] = 1;
			que.push({y, x});
		}
	}
	cout << ans << "\n";
}