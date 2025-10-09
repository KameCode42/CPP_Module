/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:50:50 by david             #+#    #+#             */
/*   Updated: 2025/10/09 17:19:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Utilisation de dynamic_cast :
- permet de convertir un pointeur ou une reference d'une classe de base
vers une classe derivee
virutal ~Base() : 
- permet de verifier quel objet a ete creer
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	random = rand() % 3;

	switch(random)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			std::cout << "Erreur" << std::endl;
			return NULL;
	}
}

void	identify(Base* p)
{
	if (p == NULL){
		std::cout << "Erreur" << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p)){
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p)){
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p)){
		std::cout << "C" << std::endl;
		return;
	}
}

void	identify(Base& p)
{
	try{
		try{
			dynamic_cast<A&>(p);
			std::cout << "A" << std::endl;
		}
		catch(...){
		}
		try{
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(...){
		}
		try{
			dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
		}
		catch(...){
		}
	}
	catch(...){
	}
}

int	main()
{
	srand (time(NULL));

	Base* var_1 = generate();
	Base* var_2 = generate();
	Base* var_3 = generate();

	std::cout << "Pointeur : " << std::endl;
	identify(var_1);
	identify(var_2);
	identify(var_3);
	std::cout << std::endl;
	std::cout << "Reference : " << std::endl;
	identify(*var_1);
	identify(*var_2);
	identify(*var_3);

	delete var_1;
	delete var_2;
	delete var_3;
	return 0;
}
