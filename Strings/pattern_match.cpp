#include <string>
#include <iostream>
#include <cctype>

bool is_char_matched(char c, char p_char)
{
	if (p_char == 'D')
		return isdigit(c);
	if (p_char == 'A')
		return isalpha(c);
	if (islower(p_char))
			return (p_char == tolower(c));
	if (p_char == '?')
		return true;
	if (ispunct(p_char))	
		return (p_char == c);
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
	    for (int j = 0; j < p_len && i + j < len; j++) {
			if (!is_char_matched(sentence[i + j], pattern[j])) {
				match.clear();
				break;
			}
			match.push_back(sentence[i + j]);
		}
		if (match.length() == p_len)
			std::cout << match << std::endl;
		match.clear();
	}
}
