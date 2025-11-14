#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

bool	is_pangram(const string &s, map<char,int> &char_count)
{
	for (char c : s) {
		if (isalpha(c))
			char_count[tolower(c)]++;
	}
	if (char_count.size() == 26)
		return true;
	return false;
}

int main()
{
	string input;
	getline(cin, input);
	map<char, int> char_count;
	if (is_pangram(input, char_count))
		cout << "Pangram" << endl;
	else
		cout << "Not Pangram" << endl;
	for (char c = 'a'; c <= 'z'; c++)
		cout << c << '-' << char_count[c] << endl;
	return 0;
}
