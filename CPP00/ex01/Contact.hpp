#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string darkestsecret;

	public:
		Contact();
		Contact(std::string input[5]);
		~Contact();
		std::string	getFirstname();
		std::string	getLastname();
		std::string	getNickname();
		std::string	getPhonenumber();
		std::string	getDarkestsecret();
};

#endif
