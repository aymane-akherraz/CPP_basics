#include <iostream>
using namespace std;

int main()
{
	float grossprice, taxrate, netprice, taxvalue;

	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;
	if (grossprice <= 0 || taxrate < 0 || taxrate > 100)
	{
		cout << "Invalid input: grossprice and taxrate should be "
			"greater than 0 and taxrate should be less than 100 \n";
		return 1;
	}
	netprice = grossprice / (1 + taxrate / 100);
	taxvalue = grossprice - netprice;
	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	return 0;
}
