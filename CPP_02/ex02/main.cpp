/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:31:24 by david             #+#    #+#             */
/*   Updated: 2025/07/05 17:10:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	testArithmetic(){
	Fixed const	a(Fixed(3.8f) * Fixed(4));
	Fixed const	b(Fixed(20.3f) + Fixed(200));
	Fixed const	c(Fixed(100) - Fixed(50));
	Fixed const	d(Fixed(55.78f) / Fixed(23));

	std::cout << "result operator (*) : " << a << std::endl;
	std::cout << "result operator (*) : " << a.toInt() << std::endl;
	std::cout << "result operator (+) : " << b << std::endl;
	std::cout << "result operator (+) : " << b.toInt() << std::endl;
	std::cout << "result operator (-) : " << c << std::endl;
	std::cout << "result operator (-) : " << c.toInt() << std::endl;
	std::cout << "result operator (/) : " << d << std::endl;
	std::cout << "result operator (/) : " << d.toInt() << std::endl;
}

void	testIncrementAndDecrement(){
	Fixed	a(1);
	Fixed	b(2);

	std::cout << a << std::endl;//1 (1 * 256) = 256
	std::cout << ++a << std::endl;//257 / 256 = 1.00391
	std::cout << a << std::endl;//1.00391
	std::cout << a++ << std::endl;//1.00391
	std::cout << a << std::endl;//258 / 256 = 1.00781
	std::cout << std::endl;
	std::cout << b << std::endl;// 2 (2 * 256) = 512
	std::cout << --b << std::endl;//511 / 256 = 1.99609375
	std::cout << b << std::endl;//1.99609375
	std::cout << b-- << std::endl;//1.99609375 (devient 510)
	std::cout << b << std::endl;//510 / 256 = 1.9921875
}

void	testComparison(){
	Fixed const	a(Fixed(10) > Fixed(5));
	Fixed const	b(Fixed(5) > Fixed(10));
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	Fixed const	c(Fixed(10) <= Fixed(10));
	Fixed const	d(Fixed(20) <= Fixed(5));
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;
	Fixed const	e(Fixed(10) == Fixed(10));
	Fixed const	f(Fixed(20) == Fixed(5));
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	std::cout << std::endl;
	Fixed const	g(Fixed(10) != Fixed(10));
	Fixed const	h(Fixed(20) != Fixed(5));
	std::cout << g << std::endl;
	std::cout << h << std::endl;
}

void	testMin(){
	Fixed	a(20);
	Fixed	b(10);
	Fixed	result;
	Fixed const	c(300);
	Fixed const	d(200);
	Fixed result2;

	result = Fixed::min(a, b);
	std::cout << "a = " << a << ", b = " << b << ", le min = " << result << std::endl;
	std::cout << std::endl;
	result2 = Fixed::min(c, d);
	std::cout << "c = " << c << ", d = " << d << ", le min = " << result2 << std::endl;
	std::cout << std::endl;
}

void	testMax(){
	Fixed	a(20);
	Fixed	b(10);
	Fixed	result;
	Fixed const	c(300);
	Fixed const	d(200);
	Fixed result2;

	result = Fixed::max(a, b);
	std::cout << "a = " << a << ", b = " << b << ", le max = " << result << std::endl;
	std::cout << std::endl;
	result2 = Fixed::max(c, d);
	std::cout << "c = " << c << ", d = " << d << ", le max = " << result2 << std::endl;
	std::cout << std::endl;
}

//5.05 = virgule flottante *256 puis roundf
//2 direct 2 * 256
int	main(void){
	std::cout << "------TEST_PDF" << std::endl;
	Fixed	a;// a._raw = 0 → a = 0/256 = 0.0
	Fixed const	b(Fixed(5.05f) * Fixed(2));//5.05 * 256 = 1293 | 2 * 256 = 512 |

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;//Pré-incrément a._raw passe de 0 à 1. Valeur = 1 / 256 = 0.00390625
	std::cout << a << std::endl;//a._raw est toujours 1 → 0.00390625
	std::cout << a++ << std::endl;//Post-incrément a++ :Renvoie d’abord l’ancienne valeur (0.00390625)Puis fait a._raw++ → a._raw passe de 1 à 2
	std::cout << a << std::endl;//Après a++, a._raw == 2 → 2 / 256 = 0.0078125
	std::cout << b << std::endl;//On retrouve b = 10.1015625 → 10.1016
	std::cout << Fixed::max( a, b ) << std::endl;//Fixed::max compare a._raw (2) et b._raw (2586), renvoie b.
	std::cout << std::endl;
	std::cout << "------TEST_ARITHMETIC" << std::endl;
	testArithmetic();
	std::cout << std::endl;
	std::cout << "------TEST_INCREMENT" << std::endl;
	testIncrementAndDecrement();
	std::cout << std::endl;
	std::cout << "------TEST_COMPARISON" << std::endl;
	testComparison();
	std::cout << std::endl;
	std::cout << "------TEST_MIN" << std::endl;
	testMin();
	std::cout << std::endl;
	std::cout << "------TEST_MAX" << std::endl;
	testMax();
	return 0;
}

/*
Multiplication (operator*) fait :

    produit 64 bits : 1293 × 512 = 662016

    décale à droite de 8 bits : 662016 >> 8 = 662016 / 256 = 2586

    construit Fixed(2586)

Valeur de b = 2586 / 256 = 10.1015625 → affiché 10.1016


result de la variable qui est incrementer ou vice versa
*/