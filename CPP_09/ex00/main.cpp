/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:26:10 by david             #+#    #+#             */
/*   Updated: 2025/11/21 11:24:33 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Erreur -> utilise ./btc <input.txt>" << std::endl;
		return 1;
	}

	BitcoinExchange	btc;

	btc.parseData("data.csv");
	//btc.parseInput(argv[1]);





	return 0;
}
