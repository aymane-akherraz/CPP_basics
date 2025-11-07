#include <iostream>
using namespace std;

int main()
{
	int bits;
	unsigned long n;

	cout << "Enter number: ";
	cin >> n;
	bits = 0;
	while (n)
	{
		if (n & 1)
			bits++;
		n >>= 1;
	}
	cout << bits << endl;
}
