#include <fstream>
#include <string>
#include <sstream>

int main() {
	{
		std::string content = "hello world";
		std::ofstream file("1.test");
		file << content;
		file.close();
		system("./replace 1.test l L");

		std::ifstream output("1.test.replace");
		std::stringstream buf;
		buf << output.rdbuf();
		std::string got = buf.str();
		std::string expect = "heLLo worLd";

		assert(expect == got);
	}
	{
		std::string content = "";
		std::ofstream file("2.test");
		file << content;
		file.close();
		system("./replace 2.test l L");

		std::ifstream output("2.test.replace");
		std::stringstream buf;
		buf << output.rdbuf();
		std::string got = buf.str();
		std::string expect = "";

		assert(expect == got);
	}
	{
		std::string content = "hello\nworld\n42";
		std::ofstream file("3.test");
		file << content;
		file.close();
		system("./replace 3.test $'\\n' ', '");

		std::ifstream output("3.test.replace");
		std::stringstream buf;
		buf << output.rdbuf();
		std::string got = buf.str();
		std::string expect = "hello, world, 42";

		assert(expect == got);
	}
}
