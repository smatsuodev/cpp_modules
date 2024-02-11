#include <fstream>
#include <iostream>
#include <sstream>

static std::string replace(
	const std::string &target,
	const std::string &old_str,
	const std::string &new_str
) {
	std::string replaced;

	for (unsigned long i = 0; i < target.length(); i++) {
		if (strncmp(target.c_str() + i, old_str.c_str(), old_str.length()) == 0) {
			replaced += new_str;
			i += old_str.length() - 1;
		} else
			replaced.push_back(target[i]);
	}

	return (replaced);
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::cout << filename << ": " << s1 << " → " << s2 << std::endl;

	std::ifstream src(filename);
	std::ofstream dst(filename + ".replace");

	std::stringstream buf;
	buf << src.rdbuf();
	dst << replace(buf.str(), s1, s2);
}
