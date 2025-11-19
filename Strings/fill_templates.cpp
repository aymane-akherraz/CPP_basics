#include <string>
#include <iostream>

void fill_templates(std::string &temp, std::string pair, size_t pos)
{
	size_t eq_pos = pair.find('=');
	if (eq_pos != std::string::npos) {
		std::string key = "[" + pair.substr(0, eq_pos) + "]";
		std::string val = pair.substr(eq_pos + 1, pos - eq_pos);
		size_t key_pos = temp.find(key);
		size_t key_len = key.size();
		while (key_pos != std::string::npos) {
			temp.replace(key_pos, key_len, val);
			key_pos = temp.find(key, key_pos + 1);
		}
	}
}

int main()
{
    std::string values;
    std::getline(std::cin, values);

    std::string temp;
    std::getline(std::cin, temp);
	std::string pair;

	size_t start_pos = 0;
	size_t pos = values.find(',');
	while (pos != std::string::npos) {
		pair = values.substr(start_pos, pos - start_pos);
		fill_templates(temp, pair, pos);
		start_pos = pos + 1;
		pos = values.find(',', pos + 1);
	}
	pair = values.substr(start_pos);
	fill_templates(temp, pair, pos);
    std::cout << temp << "\n";
}
