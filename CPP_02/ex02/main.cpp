/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:31:24 by david             #+#    #+#             */
/*   Updated: 2025/07/05 21:58:31 by david            ###   ########.fr       */
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
		std::cout << "between a first number : " << std::endl;
		std::cin >> n1;
		std::cout << "between a second number : " << std::endl;
		std::cin >> n2;

		Fixed const	a(n1);
		Fixed const	b(n2);
		Fixed	result;

		std::cout << "choose a parameter : " << std::endl;
		std::cout << "1. addition" << std::endl;
		std::cout << "2. subtraction" << std::endl;
		std::cout << "3. division" << std::endl;
		std::cout << "4. multiplication" << std::endl;
		std::cout << "5. comparison {>, <, >=, <=, == && !=}" << std::endl;
		std::cout << "6. min && max" << std::endl;
		std::cout << std::endl;
		std::cout << "-> ";
		std::cin >> choice;
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
				result = a / b;
				std::cout << a << " / " << b << " = " << result << std::endl;
			break;
			case 4:
				result = a * b;
				std::cout << a << " * " << b << " = " << result << std::endl;
			break;
			case 5:
				result = a > b;
				std::cout << a << " bigger than " << b << " = " << result << std::endl;
				result = a < b;
				std::cout << a << " smaller than " << b << " = " << result << std::endl;
				result = a >= b;
				std::cout << a << " greater than or equal to " << b << " = " << result << std::endl;
				result = a <= b;
				std::cout << a << " smaller or equal " << b << " = " << result << std::endl;
				result = a == b;
				std::cout << a << " are equal " << b << " = " << result << std::endl;
				result = a != b;
				std::cout << a << " are different " << b << " = " << result << std::endl;
			break;
			case 6:
				std::cout << "minimum between " << a << " and " << b << " = " << Fixed::min(a, b) << std::endl;
				std::cout << "maximum between " << a << " and " << b << " = " << Fixed::max(a, b) << std::endl;
			break;
			default:
				std::cout << "invalid entry" << std::endl;
			break;
		}
		std::cout << std::endl;
		std::cout << "continue : o/n" << std::endl;
		std::cin >> run;
		system("clear");
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
