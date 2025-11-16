#include <string>
#include <iostream>

int main()
{
    std::string from;
    std::getline(std::cin, from);

    std::string to;
    std::getline(std::cin, to);

    std::string sentence;
    std::getline(std::cin, sentence);
	size_t from_len = from.length();
    size_t to_len = to.length();
	size_t pos = sentence.find(from);
	while (pos != std::string::npos) {
		sentence.replace(pos, from_len, to);
		pos = sentence.find(from, pos + to_len);
	}
    std::cout << sentence << "\n";
}
