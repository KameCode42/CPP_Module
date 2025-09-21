/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:45 by david             #+#    #+#             */
/*   Updated: 2025/09/21 10:37:05 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

void	testShrubbery(){
	std::cout << "TEST 1" << std::endl;
	AForm	*scf = NULL;
	try{
		Bureaucrat	bureaucrat("david", 130);
		scf = new ShrubberyCreationForm("Garden");
		std::cout << *scf << std::endl;
		bureaucrat.signForm(*scf);
		bureaucrat.executeForm(*scf);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete scf;
	std::cout << std::endl;
}

void	testRoboto(){
	std::cout << "TEST 2" << std::endl;
	AForm	*rrf = NULL;
	try{
		Bureaucrat	bureaucrat("david", 40);
		rrf = new RobotomyRequestForm("Robot");
		std::cout << *rrf << std::endl;
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete rrf;
	std::cout << std::endl;
}

void	testPresidential(){
	std::cout << "TEST 3" << std::endl;
	AForm	*ppf = NULL;
	try{
		Bureaucrat	bureaucrat("david", 4);
		ppf = new PresidentialPardonForm("Sauron");
		std::cout << *ppf << std::endl;
		bureaucrat.signForm(*ppf);
		bureaucrat.executeForm(*ppf);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete ppf;
	std::cout << std::endl;
}

void	testError(){
	std::cout << "TEST ERROR EXECUTION" << std::endl;
	AForm	*rrf = NULL;
	try{
		Bureaucrat	bureaucrat("david", 50);
		rrf = new RobotomyRequestForm("Robot");
		std::cout << *rrf << std::endl;
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete rrf;
	std::cout << std::endl;
}


int main(){
	system("clear");
	srand (time(NULL));

	testShrubbery();
	testRoboto();
	testPresidential();
	testError();

	return 0;
}
