#include <iostream>
using namespace std;

int main()
{
	int n;
	double pow = 1;

	cout << "Enter exponent: ";
	cin >> n;
	if (n < 0)
	{
		cout << "exponent should be positive or equal zero\n";
		return 1;
	}
	for (int i = 0; i < n; i++)
		pow /= 2;
	cout.precision(30);
	cout << pow << endl;
	return 0;
}
