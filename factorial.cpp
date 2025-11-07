#include <iostream>
using namespace std;

int main()
{
	int n;
	unsigned long f;

	cout << "n = ";
	cin >> n;
	if (n < 0)
	{
		cout << "n should be greater than or equal 0\n";
		return 1;
	}
	if (n == 0 || n == 1)
		cout << 1 << endl;
	else
	{
		f = 2;
		while (n != 2)
		{
			f *= n;
			n--;
		}
		cout << f << endl;
	}
	return 0;
}
