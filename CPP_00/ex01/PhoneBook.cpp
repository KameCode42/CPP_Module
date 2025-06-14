/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:33 by david             #+#    #+#             */
/*   Updated: 2025/06/14 14:48:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Error.hpp"

PhoneBook::PhoneBook() : _nextIndex(0), _count(0), _maxContact(8){
}
PhoneBook::~PhoneBook(){
}

void	PhoneBook::add_contact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkSecret;

	if (_count >= _maxContact)
	{
		std::cout << "The address book is full (8 contacts max). Unable to add." << std::endl;
		return;
	}
	do
	{
		std::cout << "Type a first name : ";
		std::getline(std::cin, firstName);
	}while (!isNotEmpty(firstName));
	system("clear");





	
	std::cout << "Type a last name : ";
	std::getline(std::cin, lastName);
	system("clear");
	std::cout << "Type a nick name : ";
	std::getline(std::cin, nickName);
	system("clear");
	std::cout << "Type a phone number : ";
	std::getline(std::cin, phoneNumber);
	system("clear");
	std::cout << "Type a dark secret : ";
	std::getline(std::cin, darkSecret);
	system("clear");
	if (_count <= _maxContact)
	{
		std::cout << "Contact save" << std::endl;
		_count++;
	}
	//gere les erreur avant de set


	//enregiste grace a set dans le tableau avec l index
	/*
	isNumeric(const std::string&)

	isNotEmpty(const std::string&)

	isValidPhone(const std::string&)
	*/
}
