#include <string>
#include <iostream>
#include <cctype>

bool check_type(char c, char type)
{
	if (type == 'D')
		return isdigit(c);
	if (type == 'A')
		return isalpha(c);
	if (islower(type))
			return (type == tolower(c));
	if (type == '?')
		return true;
	if (ispunct(type))	
		return (type == c);
	return (false);
}

int main()
{
    std::string pattern;
    std::getline(std::cin, pattern);

    std::string sentence;
    std::getline(std::cin, sentence);
	std::string match;
    size_t len = sentence.length();
	size_t p_len = pattern.length();
    for (int i = 0; i < len; i++) {
	    for (int j = 0; j < p_len && i < len; j++) {
			char c = pattern[j];
			if (!check_type(sentence[i], c)) {
				match.clear();
				break;
			}
			else
				match.push_back(sentence[i++]);
		}
		if (match.length() == p_len) {
			std::cout << match << std::endl;
			match.clear();
		}
	}
}
