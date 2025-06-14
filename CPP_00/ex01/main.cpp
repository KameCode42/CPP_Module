/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:47 by david             #+#    #+#             */
/*   Updated: 2025/06/14 11:00:39 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	PhoneBook;//variable phonebook pour use phonebook.add_contact etc
	std::string	line;
	std::string	add = "ADD";
	std::string	search = "SEARCH";
	std::string	exit = "EXIT";

	std::cout << "Welcome to your phonebook manager !" << std::endl;
	while (1)
	{
		std::cout << "type a command ADD, SEARCH or EXIT : ";
		std::getline(std::cin, line);
		//if (!line.compare(add))
			//PhoneBook.add_contact();
		//else if(!line.compare(search))
			//PhoneBook.search_contact()
		if (!line.compare(exit))
		{
			std::cout << "GoodBye !" << std::endl;
			break;
		}
	}
	return 0;
}
