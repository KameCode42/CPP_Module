/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:26:13 by david             #+#    #+#             */
/*   Updated: 2025/10/03 11:41:25 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*-----------------PSEUDO-----------------------*/

static bool isPseudoLiterals(const std::string& literal)
{
	return (literal == "nanf" || literal == "nan"
	|| literal == "-inff" || literal == "-inf"
	|| literal == "+inff" || literal == "+inf");
}

static void	printPseudoLiterals(const std::string& literal)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;

	if (literal == "nanf" || literal == "nan"){
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (literal == "-inff" || literal == "-inf"){
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
	else {
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
	}
}

static bool	isChar(const std::string& literal)
{
	if (literal.empty() || literal.length() != 3)
		return false;
	if (literal[0] != '\'' || literal[2] != '\'')
		return false;
	return true;
}

static bool	isInt(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-'){
		i++;
		if (i == literal.length())
			return false;
	}
	while (i < literal.length()){
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

static bool	isFloat(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-'){
		i++;
		if (i == literal.length())
			return false;
	}
	while (i < literal.length() && literal[i] != '.'){
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	if (literal[i] == '.')
		i++;
	while (i < literal.length() && literal[i] != 'f'){
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	i++;
	if (literal[literal.length() - 1] != 'f')
		return false;
	return true;
}

/*
static bool	isDouble(const std::string& literal)
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
	while (i < literal.length()){
		if (!std::isdigit(literal[i])){
			std::cout << "Error" << std::endl;
			return false;
		}
		i++;
	}
	return true;
}
*/




static void	convertToChar(double value)
{
	if (value < 0 || value > 127)
		std::cout << "char : impossible" << std::endl;
	else if (value < 32 || value == 127)
		std::cout << "char : non affichable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;
}

static void	convertToInt(double value)
{
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(value) << std::endl;
}

static void	convertToFloat(double value)
{
	
}

void	ScalarConverter::convert(const std::string& literal)
{
	if (isPseudoLiterals(literal))
	{
		printPseudoLiterals(literal);
		return;
	}
	

	//strtod convertit la chaine en double
	//strtod lit autant de caractères numériques qu’il peut et met end sur le premier caractère non reconnu.
	char	*end;
	double	value = strtod(literal.c_str(), &end);

	if (isChar(literal) == true)
	{
		value = static_cast<double>(literal[1]);
		convertToChar(value);
		convertToInt(value);
		return;
	}

	/*
	if (end == literal.c_str())
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		return;
	}
	*/
	//convertToChar(value);
	//convertToInt(value);
	return;
}
