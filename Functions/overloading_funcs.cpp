#include <iostream>
#include <cmath>
using namespace std;

void	increment(int &var, int value = 1)
{
	var += value;
}

void    increment(float &var, double value = 1.0)
{
	var += value;
}

int main(void) {

	int intvar = 0;
	float floatvar = 1.5;

	for(int i = 0; i < 10; i++)
		if(i % 2) {
			increment(intvar);
			increment(floatvar, sqrt(intvar));
		}
		else {
			increment(intvar,i);
			increment(floatvar);
		}
	cout << intvar * floatvar << endl;
	return 0;
}
