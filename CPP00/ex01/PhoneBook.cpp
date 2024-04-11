#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	PhoneBook::contactCount = 0;
	
	std::cout << "PhoneBook created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed" << std::endl;
	return ;
}

void PhoneBook::addContact()
{
	static int index = 0;
	std::string inputs[5];
	std::string prompts[5] = {"Enter the first name: ", "Enter the last name: ", "Enter the nickname: ", \
								"Enter the phone number: ", "Enter the darkest secret: "};

	for (int i = 0; i < 5; i++) {
		std::cout << prompts[i];
		if (!ProtectGetline(inputs[i]) || isAllWhiteSpace(inputs[i])) {
			std::cout << "Error: Input can't be empty" << std::endl;
			return;
		}
	}
	if (PhoneBook::contactCount == 8 && index == 8)
		index = 0;
	PhoneBook::contacts[index] = Contact(inputs);
	if (PhoneBook::contactCount < 8)
		PhoneBook::contactCount++;
	index++;
}

void PhoneBook::searchContact()
{
	int i = 0;

	if (PhoneBook::contactCount == 0)
	{
		std::cout << "Error: No contacts." << std::endl;
		return ;
	}
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	while (i < PhoneBook::contactCount)
	{
		std::cout << "|         " << i + 1 << "|";
		std::cout << std::setw(10) << char_10(PhoneBook::contacts[i].getFirstname()) << "|";
		std::cout << std::setw(10) << char_10(PhoneBook::contacts[i].getLastname()) << "|";
		std::cout << std::setw(10) << char_10(PhoneBook::contacts[i].getNickname()) << "|" << std::endl;
		i++;
	}
	std::cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	std::cout << "Enter the index of the contact you want to see: ";
	std::string input;
	if (!ProtectGetline(input))
		return ;
	try
	{
		PhoneBook::printContact(std::stoi(input));
	}
	catch (std::exception&)
	{
		std::cout << "Error: Invalid input." << std::endl;
	}
	return ;
}

void PhoneBook::printContact(int i)
{
	i--;
	if (i < 0 || i >= PhoneBook::contactCount)
	{
		std::cout << "Error: Invalid index." << std::endl;
		return ;
	}
	std::cout << "First name: " << PhoneBook::contacts[i].getFirstname() << std::endl;
	std::cout << "Last name: " << PhoneBook::contacts[i].getLastname() << std::endl;
	std::cout << "Nickname: " << PhoneBook::contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << PhoneBook::contacts[i].getPhonenumber() << std::endl;
	std::cout << "Darkest secret: " << PhoneBook::contacts[i].getDarkestsecret() << std::endl;
	return ;
}
