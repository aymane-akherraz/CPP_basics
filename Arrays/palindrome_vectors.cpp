#include <iostream>

using namespace std;

int main(void) {

	int vector[] = {1, 7, 3, 8, 3, 7, 1};
	bool is_palindrome = true;
	int n = sizeof(vector) / sizeof(vector[0]);
	int j = n - 1;
	for (int i = 0; i <= j ; i++)
	{
		if (vector[i] != vector[j])
			is_palindrome = false;
		j--;
	}
	if (is_palindrome)
		cout << "It's a palindrome";
	else
		cout << "It isn't a palindrome";
	cout << endl;
	return 0;
}
