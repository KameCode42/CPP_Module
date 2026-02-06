/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:33:03 by david             #+#    #+#             */
/*   Updated: 2026/02/06 11:33:06 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "Erreur" << std::endl;
		return 1;
	}

	PmergeMe pmergeme;

	if (pmergeme.parse(argc, argv))
		return 1;

	pmergeme.run();
	
	return 0;
}
