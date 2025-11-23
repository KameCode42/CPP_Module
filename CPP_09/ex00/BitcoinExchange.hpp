/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:18:11 by david             #+#    #+#             */
/*   Updated: 2025/11/23 16:14:29 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& src);
		BitcoinExchange&	operator=(BitcoinExchange const& other);
		~BitcoinExchange();

		void	parseData(std::string const& filename);
		void	parseInput(std::string const& filename);
		void	calculAndPrint(std::string& date, double price);

	private:
		std::map<std::string, double>	_price;
};

#endif
