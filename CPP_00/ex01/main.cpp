/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:47 by david             #+#    #+#             */
/*   Updated: 2025/06/16 18:21:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	PhoneBook;
	std::string	line;
	std::string	add = "ADD";
	std::string	search = "SEARCH";
	std::string	exit = "EXIT";
	(void)argv;

	if (argc != 1){
		std::cout << "Use './phonebook'" << std::endl;
		return 1;
	}
	system("clear");
	std::cout << "Welcome to your phonebook manager !" << std::endl;
	std::cout << std::endl;
	while (1){
		std::cout << "Type a command : " << std::endl;
		std::cout << "- ADD" << std::endl;
		std::cout << "- SEARCH" << std::endl;
		std::cout << "- EXIT" << std::endl;
		std::getline(std::cin, line);
		system("clear");
		if (!line.compare(add))
			PhoneBook.add_contact();
		else if(!line.compare(search))
			PhoneBook.search_contact();
		else if (!line.compare(exit)){
			std::cout << "GoodBye !" << std::endl;
			break;
		}
		else{
			std::cout << "Error: command invalid" << std::endl;
			std::cout << std::endl;
		}
		if (std::cin.eof()){
			std::cout << "Error: program closing" << std::endl;
			return 1;
		}
	}
	return 0;
}
