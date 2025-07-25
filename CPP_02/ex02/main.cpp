/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:31:24 by david             #+#    #+#             */
/*   Updated: 2025/07/25 16:39:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	a = 0
	print 1 : 0
	pre-incremente : 0 devient 1 -> 1/256
	print 2 : 0.00390625
	print 3 : 0.00390625
	post-incremente : 1 devient 2, affiche ancienne valeur
	print 4 : 0.00390625
	print 5 : 0.0078125 nouvelle valeur, 2/256
	
	b : 5.05 * 2
	5.05 * 256 = 1292.8 roundf 1293
	2 * 256 = 512
	1293 * 512 = 662016
	662016 / 256 = 2586
	2586 / 256 = 10.10
	print 6 : valeur de b = 10.1016
	print 7 : valeur max entre a et b
*/

void	programFixed(){
	std::cout << "------MY_PROGRAM" << std::endl;
	float	n1;
	float	n2;
	int		choice;
	char	run;

	do{
		std::cout << "choisi un parametre : " << std::endl;
		std::cout << "1. addition" << std::endl;
		std::cout << "2. soustraction" << std::endl;
		std::cout << "3. division" << std::endl;
		std::cout << "4. multiplication" << std::endl;
		std::cout << "5. comparaison {>, <, >=, <=, == && !=}" << std::endl;
		std::cout << "6. min && max" << std::endl;
		std::cout << std::endl;
		std::cout << "-> ";
		std::cin >> choice;
		if (choice <= 0 || choice > 6)
		{
			std::cout << "entre invalide" << std::endl;
			return;
		}
		std::cout << "entre un premier nombre : " << std::endl;
		std::cin >> n1;
		std::cout << "entre un deuxieme nombre : " << std::endl;
		std::cin >> n2;
		std::cout << std::endl;

		Fixed const	a(n1);
		Fixed const	b(n2);
		Fixed	result;

		switch(choice){
			case 1:
				result = a + b;
				std::cout << a << " + " << b << " = " << result << std::endl;
			break;
			case 2:
				result = a - b;
				std::cout << a << " - " << b << " = " << result << std::endl;
			break;
			case 3:
				if (b == Fixed(0)){
					std::cout << "erreur: division par 0 impossible" << std::endl;
					break;
				}
				result = a / b;
				std::cout << a << " / " << b << " = " << result << std::endl;
			break;
			case 4:
				result = a * b;
				std::cout << a << " * " << b << " = " << result << std::endl;
			break;
			case 5:
				result = a > b;
				std::cout << a << " plus grand que " << b << " = " << result << std::endl;
				result = a < b;
				std::cout << a << " plus petit que " << b << " = " << result << std::endl;
				result = a >= b;
				std::cout << a << " plus grand ou egal " << b << " = " << result << std::endl;
				result = a <= b;
				std::cout << a << " plus petit ou egal " << b << " = " << result << std::endl;
				result = a == b;
				std::cout << a << " et " << b << " sont egaux " << " = " << result << std::endl;
				result = a != b;
				std::cout << a << " et " << b << " sont differents " << " = " << result << std::endl;
			break;
			case 6:
				std::cout << "min entre " << a << " et " << b << " = " << Fixed::min(a, b) << std::endl;
				std::cout << "max entre " << a << " et " << b << " = " << Fixed::max(a, b) << std::endl;
			break;
			default:
			break;
		}
		std::cout << std::endl;
		std::cout << "continue : o/n" << std::endl;
		std::cin >> run;
		system("clear");
		if (std::cin.eof()){
			std::cout << "Error: program closing" << std::endl;
			exit(EXIT_FAILURE);
		}
	}while(run == 'o');
	std::cout << "GoodBye!" << std::endl;
}

int	main(void){
	system("clear");
	std::cout << "------TEST_PDF" << std::endl;

	Fixed	a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;

	programFixed();
	return 0;
}
