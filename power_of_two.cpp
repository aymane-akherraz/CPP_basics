#include <iostream>
using namespace std;

int main()
{
	int n;
	unsigned long pow = 1;

	cout << "Enter exponent: ";
	cin >> n;
	if (n < 0 || n > 63)
	{
		cout << "exponent can be only between 0 and 63\n";
		return 1;
	}
	for (int i = 0; i < n; i++)
		pow *= 2;
	cout << pow << endl;
	return 0;
}
