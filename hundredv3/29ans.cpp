#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r, c;
	cin >> r >> c;
	int sy, sx;
	cin >> sy >> sx;
	int gy, gx;
	cin >> gy >> gx;

	vector<vector<char>> data(r, vector<char>(c));
	vector<vector<int>> checked(r, vector<int>(c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> data.at(i).at(j);
			checked.at(i).at(j) = -1;
		}
	}

	int p = sy - 1;
	int q = sx - 1;

	queue<int> a;
	queue<int> b;

	checked.at(p).at(q) = 0;

	while (1)
	{
		// cout << "p is " << p+1 << " q is " << q+1 << endl;
		// cout << "checked is " << checked.at(p).at(q) << endl;
		if (p - 1 >= 0 && p - 1 < r && checked.at(p - 1).at(q) == -1 && data.at(p - 1).at(q) == '.')
		{
			a.push(p - 1);
			b.push(q);
			checked.at(p - 1).at(q) = checked.at(p).at(q) + 1;
		}
		if (p + 1 >= 0 && p + 1 < r && checked.at(p + 1).at(q) == -1 && data.at(p + 1).at(q) == '.')
		{
			a.push(p + 1);
			b.push(q);
			// cout << "pushed 2" << endl;
			checked.at(p + 1).at(q) = checked.at(p).at(q) + 1;
		}
		if (q - 1 >= 0 && q - 1 < c && checked.at(p).at(q - 1) == -1 && data.at(p).at(q - 1) == '.')
		{
			a.push(p);
			b.push(q - 1);
			// cout << "pushed 3" << endl;
			checked.at(p).at(q - 1) = checked.at(p).at(q) + 1;
		}
		if (q + 1 >= 0 && q + 1 < c && checked.at(p).at(q + 1) == -1 && data.at(p).at(q + 1) == '.')
		{
			a.push(p);
			b.push(q + 1);
			// cout << "pushed 4" << endl;
			checked.at(p).at(q + 1) = checked.at(p).at(q) + 1;
		}

		if (a.empty() && b.empty())
		{
			// cout <<"end" << endl;
			break;
		}
		else
		{
			p = a.front();
			q = b.front();
			a.pop();
			b.pop();
			continue;
		}
	}
	cout << checked.at(gy - 1).at(gx - 1) << endl;
	return 0;
}
