#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	char_10(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return str;
}

bool isAllWhiteSpace(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]) == false)
			return false;
	}
	return true;
}

bool ProtectGetline(std::string& str)
{
	if (!std::getline(std::cin, str))
		std::exit(0);
	else if (str.empty())
		return false;
	return true;
}

void printAsciiArt()
{
	std::cout << " ___  _  _   ___   _  _  ___  ___   ___    ___   _  __" << std::endl;
	std::cout << "| _ \\| || | / _ \\ | \\| || __|| _ ) / _ \\  / _ \\ | |/ /" << std::endl;
	std::cout << "|  _/| __ || (_) || .` || _| | _ \\| (_) || (_) || ' < " << std::endl;
	std::cout << "|_|  |_||_| \\___/ |_|\\_||___||___/ \\___/  \\___/ |_|\\_\\" << std::endl;
}
