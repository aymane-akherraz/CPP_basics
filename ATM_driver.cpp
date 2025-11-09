#include <iostream>
using namespace std;

bool in_banknotes(int m)
{
	return (m == 50 || m == 20 || m == 10 || m == 5 || m == 1);
}

int main()
{
	int m, div;
	int banknotes[5] = {50, 20, 10, 5, 1};
	int count[5] = {0};
	cout << "Enter amount of money: ";
	cin >> m;
	if (m <= 0)
	{
		cout << "The amount should be greater than 0\n";
		return 1;
	}
	if (in_banknotes(m))
	{
		cout << m << endl;
		return 0;
	}
	for (int i = 0; m != 0 && i < 4; i++)
	{
		div = m / banknotes[i];
		if (div)
		{
			m -= banknotes[i] * div;
			count[i] += div;
		}
	}
	if (m)
		count[4] += m;
	for (int i = 0; i < 5; i++)
	{

		while (count[i]--)
			cout << banknotes[i] << ' ';
	}
	cout << endl;
}
