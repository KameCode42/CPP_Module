/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:45 by david             #+#    #+#             */
/*   Updated: 2025/09/18 09:37:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "cstdlib"

void	testSigned()
{
	std::cout << "Test signature OK :" << std::endl;
	try
	{
		Bureaucrat	bureaucrat("david", 50);
		Form	a("controle", 120, 10);
		std::cout << bureaucrat << a << std::endl;
		bureaucrat.signForm(a);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testNoSigned()
{
	std::cout << "Test signature NON OK :" << std::endl;
	try
	{
		Bureaucrat	bureaucrat("david", 121);
		Form	a("controle", 120, 10);
		std::cout << bureaucrat << a << std::endl;
		bureaucrat.signForm(a);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testErrorForm()
{
	std::cout << "Test erreur formulaire :" << std::endl;
	try
	{
		Bureaucrat	bureaucrat("david", 121);
		Form	a("controle", 151, 10);
		std::cout << bureaucrat << a << std::endl;
		bureaucrat.signForm(a);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	system("clear");

	testSigned();
	testNoSigned();
	testErrorForm();

	std::cout << "Test incrementation :" << std::endl;
	try
	{
		Bureaucrat	bureaucrat("david", 121);
		Form	a("controle", 120, 10);
		std::cout << bureaucrat << a << std::endl;
		bureaucrat.signForm(a);
		bureaucrat.increment();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(a);
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
