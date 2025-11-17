#include <iostream>
#include <algorithm>

bool are_anagarams(std::string &word_a, std::string const &word_b)
{
  std::string a = word_a;
  std::transform(a.begin(), a.end(), a.begin(), ::tolower);

  std::string b = word_b;
  std::transform(b.begin(), b.end(), b.begin(), ::tolower);

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  return (a == b);
}

int main()
{
    std::string word_a, word_b;

    std::cin >> word_a;
    std::cin >> word_b;
	if (are_anagarams(word_a, word_b))
		std::cout << "anagrams" << std::endl;
	else
		std::cout << "not anagrams" << std::endl;
}
