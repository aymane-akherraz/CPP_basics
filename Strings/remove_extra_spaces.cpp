#include <string>
#include <iostream>
#include <cctype>

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

int main()
{
	size_t count;
	std::string sentence;
	std::getline(std::cin, sentence);
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
	std::cout << sentence << "\n";
}
