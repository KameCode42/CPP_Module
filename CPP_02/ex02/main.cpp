/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:31:24 by david             #+#    #+#             */
/*   Updated: 2025/07/09 18:15:36 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
