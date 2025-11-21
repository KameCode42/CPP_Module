/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:18:11 by david             #+#    #+#             */
/*   Updated: 2025/11/21 11:24:57 by dle-fur          ###   ########.fr       */
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

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& src);
		BitcoinExchange&	operator=(BitcoinExchange const& other);
		~BitcoinExchange();
		
		void	BitcoinExchange::parseData(std::string const& filename);
		//void	BitcoinExchange::parseInput(std::string const& filename);

	private:
		std::map<std::string, double>	_price;
};

#endif
