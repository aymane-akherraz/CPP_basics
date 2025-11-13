#include <iostream>
using namespace std;

int main()
{
	int n;
	long sum;

	cout << "n = ";
	cin >> n;
	if (n >= 0 && n <= 100000)
	{
		sum = 0;
		for (int i = 1; i <= n; i++)
			sum += i;
		cout << sum << endl;
	}
	else
		cout << "Invalid input" << endl;
}
