#include <string>
#include <iostream>
#include <cctype>

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

	bool star_found = false;
	bool underscore_found = false;
	size_t start_pos = std::string::npos, new_pos;
	size_t pos = sentence.find_first_of("*_");
	while (pos != std::string::npos) {
		if (sentence[pos] == '*') {
			if (!star_found) {
				star_found = true;
				underscore_found = false;
				if (start_pos != std::string::npos && sentence[start_pos] != ' ') {
					sentence.erase(start_pos, 1);
					pos--;
				}
				start_pos = pos;
			}
			else {
				star_found = false;
				for (int i = start_pos + 1; i < pos; i++)
					sentence[i] = toupper(sentence[i]);
				sentence.erase(pos, 1);
				pos--;
			}
		}
		else {
			if (!underscore_found) {
                underscore_found = true;
				star_found = false;
				if (start_pos != std::string::npos && sentence[start_pos] != ' ') {
                    sentence.erase(start_pos, 1);
                    pos--;
                }
				start_pos = pos;
			}
            else {
                underscore_found = false;
				sentence[start_pos] = ' ';
				sentence[pos] = ' ';
				new_pos = pos;
				for (int i = start_pos + 1; i < new_pos - 1; i+=2) {
					sentence.insert(i + 1, 1, ' ');
					new_pos++;
				}
			}
		}
		pos = sentence.find_first_of("*_", pos + 1);
	}
	if (start_pos != std::string::npos && sentence[start_pos] != ' ')
		sentence.erase(start_pos, 1);
    std::cout << sentence << "\n";
}
