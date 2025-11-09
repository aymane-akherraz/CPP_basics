#include <iostream>
using namespace std;

int main()
{
	int n;
	unsigned long sum, fn_1, fn_2;

	cout << "n = ";
	cin >> n;
	if (n <= 0)
	{
		cout << "the number must be greater than 0\n";
		return 1;
	}
	if (n == 1 || n == 2)
		cout << 1 << endl;
	else
	{
		n -= 2;
		fn_1 = 1;
		fn_2 = 1;
		while (n--)
		{
			sum = fn_1 + fn_2;
			fn_2 = fn_1;
			fn_1 = sum;
		}
		cout << sum << endl;
	}
	return 0;
}
