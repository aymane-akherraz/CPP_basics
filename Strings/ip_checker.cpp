#include <iostream>
#include <stdlib.h>

using namespace std;

bool	is_valid_ip_part(string &part)
{
	if (part.size() > 3) {
		cout << "Too many characters in a part" << endl;
		return 0;
	}
	if (part.empty()) {
		cout << "Too few characters in a part" << endl;
                return 0;
	}
	for (char c : part) {
		if (!isdigit(c)) {
			cout << "Only digits and dots allowed;" << endl;
			return 0;
		}
	}
	int n = stoi(part);
	if (n > 255) {
	       cout << "Too big a value of a part" << endl;
	       return 0;
	}
	return 1;
}

int main()
{
	string ip;
	int pos;
	int parts_count = 0;
	string part;
	getline(cin, ip);
	pos = ip.find('.');
	while (pos != string::npos)
	{
		part.assign(ip, 0, pos);
		if (!is_valid_ip_part(part))
			return 1;
		parts_count++;
		if (parts_count > 3) {
			cout << "Too many parts" << endl;
                	return 1;
		}
		ip.erase(0, pos + 1);
		pos = ip.find('.');
	}
	if (parts_count < 3) {
		cout << "Incorrect parts count" << endl;
		return 1;
	}		
        else if (!is_valid_ip_part(ip))
		return 1;
	cout << "Correct IP" << endl;
}
