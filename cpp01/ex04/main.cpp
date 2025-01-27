#include <iostream>
#include <string>
#include <fstream>

std::string replaceWords(std::string text, std::string w1, std::string w2)
{
	for (size_t i = 0; i < text.size(); i++)
	{
		text.find()
	}
		
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cout << "ONLY THREE PARAMETERS" << std::endl;
		return 1;		
	}
	std::string pathToFile = argv[1];
	std::string word1 = argv[2];
	std::string word2 = argv[3];
	std::fstream new_file;
	std::string txt;

	new_file.open(pathToFile.c_str(), std::fstream::in);
	if (new_file.is_open())
	{
		std::fstream sec_file;
		std::string newPath = pathToFile + ".replace";
		sec_file.open(newPath.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
		while (getline(new_file, txt))
		{
			if (sec_file.is_open())
				sec_file << replaceWords(txt, word1, word2) << "\n";
		}
		sec_file.close();
		new_file.close();
		newPath.erase();
	}
	txt.erase();
	pathToFile.erase();
	word1.erase();
	word2.erase();
	return 0;
}
