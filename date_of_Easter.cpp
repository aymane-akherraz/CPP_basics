#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e,y,Easter;

	cout << "Enter year: ";
	cin >> y;
	if (y >= 1901 && y <= 2100)
	{
		a = y % 19;
		b = y % 4;
		c = y % 7;
		d = (a * 19 + 24) % 30;
		e = (2 * b + 4 * c + 6 * d + 5) % 7;
		Easter = d + e;
		if (Easter < 10)
			cout << "March " << Easter + 22 << endl;
		else
			cout << "April " << Easter - 9 << endl;
	}
	else
		cout << "Please enter a year between 1901 and 2100\n";
}
