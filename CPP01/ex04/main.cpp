#include <iostream>
#include <string>
#include <iosfwd>
#include <fstream>

void	replaceString(std::string &buffer, const std::string &s1, const std::string &s2){
	size_t pos = 0;
	
	while ((pos = buffer.find(s1, pos)) != std::string::npos){
		buffer = buffer.substr(0, pos) + s2 + buffer.substr(pos + s1.length());
		pos += s2.length();
	}
}

int	main(int ac, char **av){
	if (ac != 4){
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	
	const std::string filename = av[1];
	const std::string new_filename = filename + ".replace";
	const std::string s1 = av[2];
	const std::string s2 = av[3];

	std::ifstream file(filename);
	if (!file.is_open()){
		std::cout << "File not found" << std::endl;
		return 1;
	}
	std::ofstream new_file(new_filename);
	if (!new_file.is_open()){
		std::cout << "Error creating new file" << std::endl;
		return 1;
	}
	std::string	buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	replaceString(buffer, s1, s2);
	new_file << buffer;
	file.close();
}

