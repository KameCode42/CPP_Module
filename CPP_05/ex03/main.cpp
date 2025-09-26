/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:45 by david             #+#    #+#             */
/*   Updated: 2025/09/26 16:32:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void	testSchrubbery()
{
	std::cout << "TEST 1" << std::endl;
	AForm	*scf = NULL;
	try
	{
		Intern		someRandomIntern;
		Bureaucrat	boss("david", 1);

		scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
		if (scf)
		{
			boss.signForm(*scf);
			boss.executeForm(*scf);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete scf;
	std::cout << std::endl;
}
void	testRobotomy()
{
	std::cout << "TEST 2" << std::endl;
	AForm	*rrf = NULL;
	try
	{
		Intern		someRandomIntern;
		Bureaucrat	boss("david", 1);

		rrf = someRandomIntern.makeForm("robotomy request", "Robot");
		if (rrf)
		{
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete rrf;
	std::cout << std::endl;
}

void	testPresidential()
{
	std::cout << "TEST 3" << std::endl;
	AForm	*ppf = NULL;
	try
	{
		Intern		someRandomIntern;
		Bureaucrat	boss("david", 1);

		ppf = someRandomIntern.makeForm("presidential pardon", "Sauron");
		if (ppf)
		{
			boss.signForm(*ppf);
			boss.executeForm(*ppf);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete ppf;
	std::cout << std::endl;
}

void	testError()
{
	std::cout << "TEST ERROR" << std::endl;
	AForm	*ppf = NULL;
	try
	{
		Intern		someRandomIntern;
		Bureaucrat	boss("david", 1);

		ppf = someRandomIntern.makeForm("inconnu", "Sauron");
		if (ppf)
		{
			boss.signForm(*ppf);
			boss.executeForm(*ppf);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	delete ppf;
	std::cout << std::endl;
}

int main()
{
	system("clear");
	srand (time(NULL));

	testSchrubbery();
	testRobotomy();
	testPresidential();
	testError();
	
	return 0;
}