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

void	remove_spaces(std::string& sentence)
{
    size_t count;
    trim(sentence);
    const std::string whitespace = " \t\n\r\f\v";
    size_t pos = sentence.find_first_of(whitespace);
    while (pos != std::string::npos) {
        count = 1;
        while (isspace(sentence[pos + count]))
            count++;
        sentence.erase(pos, count);
        pos = sentence.find_first_of(whitespace, pos + 1);
    }
}


void	search_for_word(std::string &sentence, std::string word)
{
	size_t w_pos = sentence.find(word);
	size_t w_len = word.length();
	while (w_pos != std::string::npos) {
		if (sentence.size() == 1 || ((w_pos == 0 && sentence[w_len] == ' ')
		|| (w_pos + w_len == sentence.size() && sentence[w_pos - 1] == ' ')
		|| (sentence.size() > 2 && sentence[w_pos - 1] == ' ' && sentence[w_pos + w_len] == ' '))) {
			sentence.erase(w_pos, w_len + 1);
			w_pos = sentence.find(word, w_pos);
		}
		else
			w_pos = sentence.find(word, w_pos + 1);
	}
}

int main()
{
    std::string stop_words;
    std::getline(std::cin, stop_words);

    std::string sentence;
    std::getline(std::cin, sentence);
	std::string word;
	size_t pos, s_pos = 0;
	for (char& c : sentence)
        c = std::tolower(c);
	remove_spaces(stop_words);
	pos = stop_words.find(',');
	while (pos != std::string::npos) {
		word = stop_words.substr(s_pos, pos - s_pos);
		search_for_word(sentence, word);
		s_pos = pos + 1;
		pos = stop_words.find(',', pos + 1);
	}
	word = stop_words.substr(s_pos);
	search_for_word(sentence, word);
	std::cout << sentence << "\n";
}
