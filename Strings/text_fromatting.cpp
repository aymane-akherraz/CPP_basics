#include <string>
#include <iostream>
#include <cctype>

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

	bool star_found = false;
	bool _found = false;
	size_t s_pos = std::string::npos, new_pos;
	size_t pos = sentence.find_first_of("*_");
	while (pos != std::string::npos) {
		if (sentence[pos] == '*') {
			if (!star_found) {
				star_found = true;
				_found = false;
				if (s_pos != std::string::npos && sentence[s_pos] != ' ') {
					sentence.erase(s_pos, 1);
					pos--;
				}
				s_pos = pos;
			}
			else {
				star_found = false;
				for (int i = s_pos + 1; i < pos; i++)
					sentence[i] = toupper(sentence[i]);
				sentence.erase(pos, 1);
				pos--;
			}
		}
		else {
			if (!_found) {
                _found = true;
				star_found = false;
				if (s_pos != std::string::npos && sentence[s_pos] != ' ') {
                    sentence.erase(s_pos, 1);
                    pos--;
                }
				s_pos = pos;
			}
            else {
                _found = false;
				sentence[s_pos] = ' ';
				sentence[pos] = ' ';
				new_pos = pos;
				for (int i = s_pos + 1; i < new_pos - 1; i+=2) {
					sentence.insert(i + 1, 1, ' ');
					new_pos++;
				}
			}
		}
		pos = sentence.find_first_of("*_", pos + 1);
	}
	if (s_pos != std::string::npos && sentence[s_pos] != ' ')
		sentence.erase(s_pos, 1);
    std::cout << sentence << "\n";
}
