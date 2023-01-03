/*
	take no midterm or final => F
	midterm + final >= 80 => A
	80 > midterm + final >= 65 => B
	midterm + final >= 50 => C
	midterm + final >= 30 => D (if makeup >= 50, => C)
	midterm + final < 30 => F
*/

#include <iostream>
#include <cstdio>
using namespace std;

int	main()
{
	int		m, f, r;
	char	grd;
	while (1)
	{
		cin >> m >> f >> r;
		if (m == -1 && f == -1 && r == -1)
			return 0;
		if (m == -1 || f == -1)
			grd = 'F';
		else if (m + f >= 80)
			grd = 'A';
		else if (m + f >= 65)
			grd = 'B';
		else if (m + f >= 50)
			grd = 'C';
		else if (m + f >= 30) {
			if (r >= 50)
				grd = 'C';
			else
				grd = 'D';
		}
		else
			grd = 'F';
		cout << grd << endl;
	}
	return 0;
}