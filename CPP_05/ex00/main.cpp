/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:45 by david             #+#    #+#             */
/*   Updated: 2025/09/21 10:15:20 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testBasic(){
	std::cout << "Test Basic :" << std::endl; 
	try{
		Bureaucrat	a("david", 10);
		Bureaucrat	b("mike", 56);
		Bureaucrat	c("john", 122);
		Bureaucrat	d("akira", 90);
		std::cout << a << b << c << d << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testErrorHigh(){
	std::cout << "Test Error High :" << std::endl;
	try{
		Bureaucrat	a("david", 10);
		Bureaucrat	b("mike", 56);
		Bureaucrat	c("john", 122);
		Bureaucrat	d("akira", 0);
		std::cout << a << b << c << d << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testErrorLow(){
	std::cout << "Test Error Low :" << std::endl;
	try{
		Bureaucrat	a("david", 10);
		Bureaucrat	b("mike", 56);
		Bureaucrat	c("john", 122);
		Bureaucrat	d("akira", 155);
		std::cout << a << b << c << d << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testDecrement(){
	std::cout << "Test Decrement :" << std::endl;
	try{
		Bureaucrat	a("david", 147);
		for(int i = 0; i < 155; i++)
		{
			std::cout << a << std::endl;
			a.decrement();
		}
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testIncrement(){
	std::cout << "Test Increment :" << std::endl;
	try{
		Bureaucrat	a("david", 3);
		for(int i = 10; i > 0; i--)
		{
			std::cout << a << std::endl;
			a.increment();
		}
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(){
	system("clear");

	testBasic();
	testErrorHigh();
	testErrorLow();
	testDecrement();
	testIncrement();

	return 0;
}
