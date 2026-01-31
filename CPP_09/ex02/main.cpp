/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:49:35 by david             #+#    #+#             */
/*   Updated: 2026/01/31 11:07:28 by david            ###   ########.fr       */
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

	if (pmergeme.parseLine(argv[1]))
		return 1;

	return 0;
}
