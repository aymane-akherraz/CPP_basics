#include <iostream>

using namespace std;

int main(void) {
	double pi4 = 0, div = 1;
	long   n;

	cout << "Number of iterations? ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Invalid number of iterations\n";
		return 1;
	}
	for (long i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			pi4 += (1. / div);
		else
			pi4 -= (1. / div);
		div += 2.;
	}
	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	return 0;
}
