/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:26:13 by david             #+#    #+#             */
/*   Updated: 2025/09/27 17:53:35 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	error(const std::string& literal)
{
	size_t	i = 0;

	if (literal.empty()){
		std::cout << "Error" << std::endl;
		return false;
	}
	if (literal[i] == 32){
		std::cout << "Error" << std::endl;
		return false;
	}
	return true;
}

static bool	isInt(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-'){
		i++;
		if (i == literal.length()){
			std::cout << "Error" << std::endl;
			return false;
		}
	}
	while (i < literal.length()){
		if (!std::isdigit(literal[i])){
			std::cout << "Error" << std::endl;
			return false;
		}
		i++;
	}
	return true;
}

static bool	isFloat(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-'){
		i++;
		if (i == literal.length()){
			std::cout << "Error" << std::endl;
			return false;
		}
	}
	while (i < literal.length() && literal[i] != '.'){
		if (!std::isdigit(literal[i])){
			std::cout << "Error" << std::endl;
			return false;
		}
		i++;
	}
	if (literal[i] == '.')
		i++;
	while (i < literal.length() && literal[i] != 'f'){
		if (!std::isdigit(literal[i])){
			std::cout << "Error" << std::endl;
			return false;
		}
		i++;
	}
	i++;
	if (literal[literal.length() - 1] != 'f'){
		std::cout << "Error" << std::endl;
		return false;
	}
	return true;
}



void	ScalarConverter::convert(const std::string& literal)
{
	if (!error(literal))
		return;
	//isInt(literal);
	//if(!isFloat(literal))
		//return;
	
}
