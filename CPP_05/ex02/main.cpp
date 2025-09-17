/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:53:45 by david             #+#    #+#             */
/*   Updated: 2025/09/17 15:53:58 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "cstdlib"

void	testShrubbery()
{
	try
	{
		Bureaucrat	bureaucrat("david", 130);
		AForm	*sch = new ShrubberyCreationForm("Garden");
		std::cout << *sch << std::endl;
		sch->beSigned(bureaucrat);
		bureaucrat.executeForm(*sch);

		delete sch;
	}
	catch(std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
}

int main()
{
	testShrubbery();

	return 0;
}
