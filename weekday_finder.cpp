#include <iostream>
using namespace std;

int main()
{
	int d,m,y,weekday_num;

	cout << "Enter year: ";
	cin >> y;
	if (y >= 1901 && y <= 2100)
	{
		cout << "Enter month: ";
		cin >> m;
		if (m >= 1 && m <= 12)
		{
			cout << "Enter day number: ";
	                cin >> d;
			if (d >= 1 && d <= 31)
			{
				m -= 2;
				if (m <= 0)
				{
					m += 12;
					y--;
				}
				m = m * 83 / 32;
				m += d;
				m += y;
				m += y / 4;
				m -= y / 100;
				m += y / 400;
				weekday_num = m % 7;
				cout << weekday_num << endl;
			}
			else
				cout << "Invalid day number: day number should be between 1 and 31\n";
		}
		else
			cout << "Invalid month number: month number should be between 1 and 12\n";

	}
	else
		cout << "Please enter a year between 1901 and 2100\n";
}
