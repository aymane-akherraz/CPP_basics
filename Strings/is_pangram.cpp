#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

	string input;
	int idx;
	bool is_pangram = true;
	int letter_count[26] = {};
	getline(cin, input);
	// insert code here
	if (is_pangram)
		cout << "Pangram" << endl;
	else
		cout << "Not Pangram" << endl;
	for (int i = 'a'; i <= 'z'; i++)
		cout << char(i) << '-' << letter_count[i - 'a'] << endl;
	return 0;
}
