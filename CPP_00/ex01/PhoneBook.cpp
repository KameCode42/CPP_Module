/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:33 by david             #+#    #+#             */
/*   Updated: 2025/06/16 13:49:28 by david            ###   ########.fr       */
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

void	PhoneBook::search_contact(){
	std::string	index;
	std::string	line = "";
	std::string	first;
	std::string	last;
	std::string	nick;
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
	while (i < _count){
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i;
		std::cout << "|";
		first = this->_array[i].getFirstName();
		if (first.size() > 10)
			first = first.substr(0,9) + ".";
		std::cout << std::right << std::setw(10) << first;
		std::cout << "|";
		last = this->_array[i].getLastName();
		if (last.size() > 10)
			last = last.substr(0,9) + ".";
		std::cout << std::right << std::setw(10) << last;
		std::cout << "|";
		nick = this->_array[i].getNickName();
		if (nick.size() > 10)
			nick = nick.substr(0,9) + ".";
		std::cout << std::right << std::setw(10) << nick;
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << std::endl;
	do{
		std::cout << "Enter an index to display a contact" << std::endl;
		std::getline(std::cin, index);
	}while(!validIndex(index));
	i = index[0] - '0';
	std::cout << "First Name : " << this->_array[i].getFirstName() << std::endl;
	std::cout << "Last Name : " << this->_array[i].getLastName() << std::endl;
	std::cout << "Nick Name : " << this->_array[i].getNickName() << std::endl;
	std::cout << "Phone Number : " << this->_array[i].getPhoneNumber() << std::endl;
	std::cout << "Dark Secret : " << this->_array[i].getDarkSecret() << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter to return to the menu" << std::endl;
	std::getline(std::cin, line);
	system("clear");
}
