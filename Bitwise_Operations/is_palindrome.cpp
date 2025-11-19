#include <iostream>

using namespace std;

int main(void) {

	int i;
	unsigned short int val, r_val, bit;
	bool is_palindrome = false;

	cout << "value = ";
	cin >> val;
	i = 0;
	r_val = 0; // this will be the reversed value of val
	while (i < 16)
	{
		bit = (val >> i) & 1;
		if (bit)
			r_val |= bit << (15 - i); // we use | to set the bit in the corresponding position
		i++;
	}
	ispalindrome = val == r_val; // val is a palindrome if it is equal to r_val
	if (is_palindrome)
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl;	
	return 0;
}
