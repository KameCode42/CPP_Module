/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:45 by david             #+#    #+#             */
/*   Updated: 2025/09/18 14:02:36 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

/*
void	testShrubbery()
{
	std::cout << "TEST 1" << std::endl;
	AForm	*sch = NULL;
	try{
		Bureaucrat	bureaucrat("david", 130);
		sch = new ShrubberyCreationForm("Garden");
		std::cout << *sch << std::endl;
		bureaucrat.signForm(*sch);
		bureaucrat.executeForm(*sch);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete sch;
	std::cout << std::endl;
}

void	testRoboto()
{
	std::cout << "TEST 2" << std::endl;
	AForm	*rob = NULL;
	try{
		Bureaucrat	bureaucrat("david", 40);
		rob = new RobotomyRequestForm("Robot");
		std::cout << *rob << std::endl;
		bureaucrat.signForm(*rob);
		bureaucrat.executeForm(*rob);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete rob;
	std::cout << std::endl;
}

void	testPresidential()
{
	std::cout << "TEST 3" << std::endl;
	AForm	*pres = NULL;
	try{
		Bureaucrat	bureaucrat("david", 4);
		pres = new PresidentialPardonForm("Sauron");
		std::cout << *pres << std::endl;
		bureaucrat.signForm(*pres);
		bureaucrat.executeForm(*pres);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete pres;
	std::cout << std::endl;
}

int main(){
	system("clear");
	srand (time(NULL));

	testShrubbery();
	testRoboto();
	testPresidential();

	return 0;
}
*/

int main(){


	return 0;
}