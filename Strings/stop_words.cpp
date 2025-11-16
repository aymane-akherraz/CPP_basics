#include <string>
#include <iostream>

int main()
{
    std::string stop_words;
    std::getline(std::cin, stop_words);

    std::string sentence;
    std::getline(std::cin, sentence);
	size_t pos, s_pos = 0, w_pos;
	std::string s_word;
	for (char& c : sentence) {
        c = std::tolower(c);
    }
	size_t w_len;
	pos = stop_words.find(',');
	while (pos != std::string::npos) {
		s_word = stop_words.substr(s_pos, pos - s_pos);
		std::cout << s_word << std::endl;
		w_pos = sentence.find(s_word);
		w_len = s_word.length();
		while (w_pos != std::string::npos) {
			sentence.erase(w_pos, w_len);
			w_pos = sentence.find(s_word);
		}
		s_pos = pos + 1;
		pos = stop_words.find(',', pos + 1);
	}
	s_word = stop_words.substr(s_pos);
	w_pos = sentence.find(s_word);
	w_len = s_word.length();
	while (w_pos != std::string::npos) {
		sentence.erase(w_pos, w_len);
		w_pos = sentence.find(s_word);
	}
	std::cout << sentence << "\n";
}
