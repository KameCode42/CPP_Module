/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:45 by david             #+#    #+#             */
/*   Updated: 2025/08/31 14:49:12 by david            ###   ########.fr       */
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
		a.beSigned(bureaucrat);
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
		a.beSigned(bureaucrat);
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
		a.beSigned(bureaucrat);
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

	return 0;
}
