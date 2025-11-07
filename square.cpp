#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter square side size: ";
	cin >> n;
	if (n <= 1)
	{
		cout << "The length should be greater than one\n";
		return 1;
	}
	if (n > 99)
	{
		cout << "Sorry, the side size is too big\n";
		return 1;
	}
	cout << '+';
	for(int i = 0; i < n - 2; i++)
		cout << '-';
	cout << '+' << endl;
	for(int i = 0; i < n - 2; i++) {
		cout << '|';
		for(int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '|' << endl;
	}
	cout << '+';
	for(int i = 0; i < n - 2; i++)
		cout << '-';
	cout << '+' << endl;
	return 0;
}
