#include <string>
#include <array>
#include <iostream>
#include <cctype>

void show_err(int i)
{
	switch (i) {
    case 0:
        std::cout << "The password must be 8 characters long\n";
        break;
    case 1:
        std::cout << "The password must have at least one upper case letter\n";
        break;
	case 2:
        std::cout << "The password must have at least one lower case letter\n";
        break;
	case 3:
        std::cout << "The password must have at least one digit\n";
        break;
	case 4:
        std::cout << "The password must have at least one special character\n";
        break;
	}
}

int main()
{
    std::string password;
    std::getline(std::cin, password);

	// flags[0] = length check, the rest default to false
	std::array<bool, 5> flags = { password.size() >= 8 };

	for (char c : password) {
		if (!flags[1] && isupper(c)) flags[1] = true;
        else if (!flags[2] && islower(c)) flags[2] = true;
        else if (!flags[3] && isdigit(c)) flags[3] = true;
        else if (!flags[4] && ispunct(c)) flags[4] = true;

		if (flags[1] && flags[2] && flags[3] && flags[4]) break;
	}

	bool is_valid = true;
	for (int i = 0; i < 5; i++) {
		if (!flags[i]) {
			show_err(i);
			is_valid = false;
		}
	}

	if (is_valid)
		std::cout << "The password is valid\n";
    return 0;
}
