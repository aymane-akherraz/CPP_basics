#include <string>
#include <iostream>

void trim(std::string& s) {
    const std::string whitespace = " \t\n\r\f\v";
    size_t first = s.find_first_not_of(whitespace);
    if (first == std::string::npos) {
        s.clear();
        return;
    }
    size_t last = s.find_last_not_of(whitespace);
    s.assign(s.substr(first, (last - first + 1)));
}

void remove_extra_spaces(std::string& sentence)
{
    size_t count;
    trim(sentence);
    const std::string whitespace = " \t\n\r\f\v";
    size_t pos = sentence.find_first_of(whitespace);
    while (pos != std::string::npos) {
        count = 1;
        while (isspace(sentence[pos + count]))
            count++;
        if (count > 1 || sentence[pos] != ' ') {
            sentence.erase(pos, count);
            sentence.insert(pos, 1, ' ');
        }
        pos = sentence.find_first_of(whitespace, pos + 1);
    }
}

int main()
{
	size_t pos, w_pos = 0;
	std::string word;
    std::string sentence;
	std::string separators = ",.;:!?";
    std::getline(std::cin, sentence);
	remove_extra_spaces(sentence);
	pos = sentence.find(' ');
	while (pos != std::string::npos) {
		if (separators.find(sentence[pos + 1]) == std::string::npos) {
			word = sentence.substr(w_pos, pos - w_pos);
			if (sentence.find(word, pos) != std::string::npos)
				sentence.erase(w_pos, (pos - w_pos) + 1);
			w_pos = pos + 1;
		}
		pos = sentence.find(' ', pos + 1);
	}
    std::cout << sentence << "\n";
}
