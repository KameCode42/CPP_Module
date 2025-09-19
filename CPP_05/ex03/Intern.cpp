/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:58:19 by david             #+#    #+#             */
/*   Updated: 2025/09/19 11:17:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
}

Intern::Intern(Intern const& src)
{
	*this = src;
}

Intern&	Intern::operator=(Intern const& other)
{
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "L'intern est detruit" << std::endl;
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	std::string	array[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	
	while (i < 3)
	{
		if (array[i] == form)
			break;
		i++;
	}
	
	switch(i)
	{
		case 0:
			std::cout << "Intern a creer " << array[i] << std::endl;
			return new ShrubberyCreationForm(target);
			break;
		case 1:
			std::cout << "Intern a creer " << array[i] << std::endl;
			return new RobotomyRequestForm(target);
			break;
		case 2:
			std::cout << "Intern a creer " << array[i] << std::endl;
			return new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::FormNoExist();
			break;
	}
}
