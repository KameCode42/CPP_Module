/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:26:13 by david             #+#    #+#             */
/*   Updated: 2025/10/04 13:27:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
PSEUDO:
- nan et nanf = resultat indefini -> 0.0/0.0
- inf et inff = valeur flottante infini
- inf pour double, inff pour float

CHAR:
- la chaine doit etre de longueur 3 et fermer de '' -> "'a'"

INT:
- la chaine ne doit pas etre "+ ou -" sinon passer le signe
- la chaine ne doit contenir que des digits

FLOAT:
- la chaine ne doit pas etre que "+ ou -" sinon passer le signe
- rechercher le point dans la chaine
- variable qui contient avant le point
- variable qui contient apres le point
- si le point est trouver, extraire apres le point
- si la chaine avant le point est vide et que la longueur <= 1, false (.f)
- parcours before, controle si que des digits
- si apres le point = vide ou que != 'f', ce n est pas un float
- si after = 4.f = true =  un float
- parcours after, controle si que des digits

DOUBLE:
- la chaine ne doit pas etre que "+ ou -" sinon passer le signe
- rechercher le point dans la chaine
- variable qui contient avant le point
- variable qui contient apres le point
- si before et after sont vide = false ("+.")
- parcours before, controle si que des digits
- parcours after, controle si que des digits

CONVERT:
- si la chaine est vide = conversion impossible
- si la chaine est un pseudo literal = print pseudo
- utilisation de strtod, convertit la chaine en double, et
lit autant de caracteres numeriques qu'il peut,et
met end sur le premier caractere non reconnu
- condition pour les 4 conversion possible
- si end == un caractere non conforme ou
si la chaine en contient = conversion impossible
*/

/*---------------------------PSEUDO------------------------------*/

static bool isPseudoLiterals(const std::string& literal){
	return (literal == "nanf" || literal == "nan"
	|| literal == "-inff" || literal == "-inf"
	|| literal == "+inff" || literal == "+inf");
}

static void	printPseudoLiterals(const std::string& literal){
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

/*---------------------------CHAR--------------------------------*/

static bool	isChar(const std::string& literal){
	if (literal.empty() || literal.length() != 3)
		return false;
	if (literal[0] != '\'' || literal[2] != '\'')
		return false;
	return true;
}

static void	convertToChar(double value){
	if (value < 0 || value > 127)
		std::cout << "char : impossible" << std::endl;
	else if (value < 32 || value == 127)
		std::cout << "char : non affichable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;
}

/*---------------------------INT---------------------------------*/

static bool	isInt(const std::string& literal){
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

static void	convertToInt(double value){
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(value) << std::endl;
}

/*---------------------------FLOAT-------------------------------*/

static bool	isFloat(const std::string& literal){
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-'){
		i++;
		if (i == literal.length())
			return false;
	}

	size_t	point = literal.find('.');
	std::string	beforePoint = literal.substr(i, point - i);
	std::string	afterPoint;

	if (point != std::string::npos)
		afterPoint = literal.substr(point + 1);
	else
		afterPoint = "";

	if (beforePoint.empty() && afterPoint.length() <= 1)
		return false;
	
	for (size_t j = 0; j < beforePoint.length(); j++){
		if (!std::isdigit(beforePoint[j]))
			return false;
	}

	if (afterPoint.empty() || afterPoint.back() != 'f')
		return false;

	if (afterPoint.length() == 1)
		return true;

	
	for (size_t j = 0; j < afterPoint.length() - 1; j++){
		if (!std::isdigit(afterPoint[j]))
			return false;
	}
	return true;
}

static void	convertToFloat(double value){
	std::cout << "float : " << std::fixed << std::setprecision(2)
	<< static_cast<float>(value) << "f" << std::endl;
}

/*---------------------------DOUBLE------------------------------*/

static bool	isDouble(const std::string& literal){
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-'){
		i++;
		if (i == literal.length())
			return false;
	}

	size_t	point = literal.find('.');
	std::string	beforePoint = literal.substr(i, point - i);
	std::string	afterPoint;

	if (point != std::string::npos)
		afterPoint = literal.substr(point + 1);
	else
		afterPoint = "";

	if (beforePoint.empty() && afterPoint.empty())
		return false;

	for (size_t j = 0; j < beforePoint.length(); j++){
		if (!std::isdigit(beforePoint[j]))
			return false;
	}
	for (size_t j = 0; j < afterPoint.length(); j++){
		if (!std::isdigit(afterPoint[j]))
			return false;
	}
	return true;
}

static void	convertToDouble(double value){
	std::cout << "double : " << std::fixed << std::setprecision(2)
	<< static_cast<double>(value) << std::endl;
}

/*---------------------------PRINT-------------------------------*/

static void	printAll(double value){
	convertToChar(value);
	convertToInt(value);
	convertToFloat(value);
	convertToDouble(value);
	return;
}

static void	printImpossibleAll(){
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
	return;
}

/*---------------------------STATIC METHOD-----------------------*/

void	ScalarConverter::convert(const std::string& literal){
	if (literal.empty()){
		printImpossibleAll();
		return;
	}
	if (isPseudoLiterals(literal)){
		printPseudoLiterals(literal);
		return;
	}

	char	*end;
	double	value = strtod(literal.c_str(), &end);

	if (isChar(literal) == true){
		value = static_cast<double>(literal[1]);
		printAll(value);
		return;
	}
	if (isInt(literal) == true){
		printAll(value);
		return;
	}
	if (isFloat(literal) == true){
		printAll(value);
		return;
	}
	if (isDouble(literal) == true){
		printAll(value);
		return;
	}
	if (end == literal.c_str() || *end != '\0'){
		printImpossibleAll();
		return;
	}
	return;
}
