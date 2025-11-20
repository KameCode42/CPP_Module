/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:18:11 by david             #+#    #+#             */
/*   Updated: 2025/11/20 16:07:08 by david            ###   ########.fr       */
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
		
		void	parseData();



	private:
		std::map<std::string, double>	_price;
};

#endif
