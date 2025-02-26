#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main() {
	PhoneBook pb;
	std::string command = "";

	printAsciiArt();
	while (command != "EXIT")
	{
		std::cout << "Enter a command: ";
		if (!ProtectGetline(command))
			continue ;
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "")
			continue ;
		else if (command != "EXIT")
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
