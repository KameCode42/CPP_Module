/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:17:36 by dle-fur           #+#    #+#             */
/*   Updated: 2025/07/25 16:38:50 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
Sommet A = (a.x, a.y)
Sommet B = (b.x, b.y)
Sommet C = (c.x, c.y)
Point coord = (p.x, p.y)
test false : 5.0 > c.y(4.0) donc hors triangle
*/

int	main(void){
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(2.5f, 4.0f);
	Point	point(3.0f, 1.0f);
	//Point	point(3.0f, 5.0f); test false

	if (bsp(a, b, c, point) == true)
		std::cout << "le point est dans le triangle" << std::endl;
	else
		std::cout << "le point n'est pas dans le triangle" << std::endl;
	return 0;
}
