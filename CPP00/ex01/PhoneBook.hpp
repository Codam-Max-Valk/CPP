#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
	int		contactCount;
	Contact	contacts[8];
public:

	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& src);
	void addContact();
	void searchContact();
	void printContact(int i);
};

std::string	char_10(std::string str);
void		printAsciiArt();
bool		ProtectGetline(std::string& str);
bool		isAllWhiteSpace(std::string str);



#endif
