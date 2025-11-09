#include <iostream>
using namespace std;

int main()
{
	int c0, steps;

	cout << "Enter number: "; 
	cin >> c0;
	if (c0 <= 0)
	{
		cout << "The number must be non-negative and non-zero\n";
		return 1;
	}
	steps = 0;
	while (c0 != 1)
	{
		if (c0 % 2)
			c0 = 3 * c0 + 1;
		else
			c0 /= 2;
		cout << c0 << endl;
		steps++;
		
	}
	cout << "steps = " << steps << endl;
	return 0;
}
