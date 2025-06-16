/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:33 by david             #+#    #+#             */
/*   Updated: 2025/06/16 12:10:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Error.hpp"

PhoneBook::PhoneBook() : _nextIndex(0), _count(0), _maxContact(8){
}
PhoneBook::~PhoneBook(){
}

void	PhoneBook::add_contact(){
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkSecret;

	if (_nextIndex == 8)
		_nextIndex = 0;
	do{
		std::cout << "Type a first name : ";
		std::getline(std::cin, firstName);
	}while (!validText(firstName));
	system("clear");
	do{
		std::cout << "Type a last name : ";
		std::getline(std::cin, lastName);
	}while (!validText(lastName));
	system("clear");
	do{
		std::cout << "Type a nick name : ";
		std::getline(std::cin, nickName);
	}while (!validText(nickName));
	system("clear");
	do{
		std::cout << "Type a phone number : ";
		std::getline(std::cin, phoneNumber);
	}while (!validNumber(phoneNumber));
	system("clear");
	do{
		std::cout << "Type a dark secret : ";
		std::getline(std::cin, darkSecret);
	}while (!validText(darkSecret));
	system("clear");
	this->_array[this->_nextIndex].setFirstName(firstName);
	this->_array[this->_nextIndex].setLastName(lastName);
	this->_array[this->_nextIndex].setNickName(nickName);
	this->_array[this->_nextIndex].setPhoneNumber(phoneNumber);
	this->_array[this->_nextIndex].setDarkSecret(darkSecret);
	this->_nextIndex++;
	if (_count <= _maxContact){
		std::cout << "Contact save" << std::endl;
		_count++;
	}
}

void	PhoneBook::search_contact()
{
	std::string	index;
	int	i = 0;

	std::cout << "|";
	std::cout << std::right << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Nick Name";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < _count)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::right << std::setw(10) << this->_array[i].getFirstName().substr(0,9) + ".";
		std::cout << "|";
		std::cout << std::right << std::setw(10) << this->_array[i].getLastName().substr(0,9) + ".";;
		std::cout << "|";
		std::cout << std::right << std::setw(10) << this->_array[i].getNickName().substr(0,9) + ".";;
		std::cout << "|" << std::endl;
		i++;
	}
	do
	{
		std::cout << "Enter an index to display a contact" << std::endl;
		std::getline(std::cin, index);
	}while(!validIndex(index));
}
