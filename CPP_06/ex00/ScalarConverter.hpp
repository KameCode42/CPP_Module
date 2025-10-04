/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:21:07 by david             #+#    #+#             */
/*   Updated: 2025/10/04 11:06:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cfloat>

class	ScalarConverter
{
	public:
		static void	convert(const std::string& literal);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& src);
		ScalarConverter&	operator=(ScalarConverter const& other);
		~ScalarConverter();
};

#endif