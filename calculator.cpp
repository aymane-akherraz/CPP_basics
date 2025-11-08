#include <iostream>
using namespace std;

int main()
{
	int choice = 1;
	double a, b;

	while (choice)
	{
		cout << "MENU:\n\n";
		cout << "0 - exit\n";
		cout << "1 - addition\n";
		cout << "2 - subtraction\n";
		cout << "3 - multiplication\n";
		cout << "4 - division" << endl;
		cout << "Your choice?\n";
		cin >> choice;
		if (choice >= 1 && choice <= 4)
		{
			cout << "Enter first number: ";
			cin >> a;
			cout << "Enter second number: ";
			cin >> b;
		}
		switch(choice) {
			case 0: break;
			case 1: cout << "A + B = " << a + b << endl; break;
			case 2: cout << "A - B = " << a - b << endl; break;
			case 3: cout << "A * B = " << a * b << endl; break;
			case 4: if (b == 0.0)
				cout << "I cannot divide by 0 - sorry" << endl;
			else
				cout << "A / B = " << a / b << endl;
				break;
			default: cout << "Bad option: " << choice << endl;
		}
	}
	return 0;
}
