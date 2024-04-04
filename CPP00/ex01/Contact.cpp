#include <iostream>
#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

Contact::Contact(std::string input[5])
{
	this->firstname = input[0];
	this->lastname = input[1];
	this->nickname = input[2];
	this->phonenumber = input[3];
	this->darkestsecret = input[4];
}

std::string Contact::getFirstname()
{
	return (this->firstname);
}

std::string Contact::getLastname()
{
	return (this->lastname);
}

std::string Contact::getNickname()
{
	return (this->nickname);
}

std::string Contact::getPhonenumber()
{
	return (this->phonenumber);
}

std::string Contact::getDarkestsecret()
{
	return (this->darkestsecret);
}

