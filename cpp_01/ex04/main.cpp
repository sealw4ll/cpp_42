#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::endl;

string line(std::ifstream &file_in)
{
	string ret;
	string line;
	 while (std::getline(file_in, line))
        ret.append(line).append("\n");
	return ret;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		cout << "please input in format [<filename> <string to find> <string to replace>]" << endl;
		return 1;
	}

	string filename;
	string replaceName;
	std::ifstream file_in;
	std::ofstream file_out;
	size_t index = 0;
	string find(av[2]);
	string replace(av[3]);

	filename.assign(av[1]);
	replaceName.assign(av[1]).append(".replace");
	if (!find.length() || !replace.length() || !filename.length())
	{
		cout << "empty inputs are invalid" << endl;
		return 1;
	}
	file_in.open(filename, std::ios::in);

	string text = line(file_in);
	string ret;

	size_t findex;
	while (index < text.length())
	{
		findex = text.find(find, index);
		// cout << findex << endl;
		if (index == findex)
		{
			ret.append(replace);
			index += find.length();
		}
		else
		{
			ret.push_back(text[index]);
			++index;
		}
	}
	file_out.open(replaceName, std::ios::out);
	file_out.write(ret.c_str(), ret.length() - 1);
}