/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:25:56 by david             #+#    #+#             */
/*   Updated: 2025/11/20 16:21:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
date | value       (input.txt)
date,price         (data.csv)
*/

/*
//bisextil = 29 jours = tous les 4 ans
// regle : (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)
//exemple : 2024 % 4 = 0 ok, 2024 % 100 = 20,24 reste 24 pas ok donc bisextil
*/

#include "BitcoinExchange.hpp"

/*=== Constructeur ===*/

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange(BitcoinExchange const& src) : _price(src._price) {};

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& other){
	if (this != &other){
		_price = other._price;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {};

/*==================================================================================*/

/*=== Fonction fichier data ===*/

static bool	validDate(std::string const& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string	y = date.substr(0, 4);
	std::string	m = date.substr(5, 2);
	std::string	d = date.substr(8, 2);

	//verification annee
	for (int i = 0; i < y.size(); i++){
		if (!std::isdigit(y[i]))
			return false;
	}
	int	year = std::atoi(y.c_str());
	if (year < 0)
		return false;

	//verification mois
	for (int i = 0; i < m.size(); i++){
		if (!std::isdigit(m[i]))
			return false;
	}
	int	month = std::atoi(m.c_str());
	if (month < 1 || month > 12)
		return false;

	//verification bisextil
	int	maxDays = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDays = 30;
	else
		maxDays = 31;
	if (month == 2){
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			maxDays = 29;
		else
			maxDays = 28;
	}

	//verification jour
	for (int i = 0; i < d.size(); i++){
		if (!std::isdigit(d[i]))
			return false;
	}
	int	day = std::atoi(d.c_str());
	if (day < 1 || day > maxDays)
		return false;

	return true;
}

static bool	validPrice(std::string const& value, bool input)
{
	size_t	i = 0;

	if (value.empty())
		return false;

	if (value[0] == '.')
		return false;

	if (std::count(value.begin(), value.end(), '.') > 1)//algo pour trouver le nombre de .
		return false;

	size_t		point = value.find('.');


	std::string	beforePoint;
	std::string	afterPoint;

	
	if (point != std::string::npos)//si une sous chaine est trouver
	{
		beforePoint = value.substr(i, point - i);
		afterPoint = value.substr(point + 1);
	}
	else
	{
		beforePoint = value;
		afterPoint = "";
	}


	for (size_t j = 0; j < beforePoint.size(); j++)
	{
		if (!std::isdigit(beforePoint[j]))
		{
			return false;
		}
	}

	for (size_t j = 0; j < afterPoint.size(); j++)
	{
		if (!std::isdigit(afterPoint[j]))
		{
			return false;
		}
	}

	char	*end;
	double	price = strtod(value.c_str(), &end);

	
	if (*end != '\0')//reste des caractere invalide
		return false;
	
	if (price < 0)
		return false;

	if (input == true)
	{
		if (price > 1000)
			return false;
	}
	
	return true;
}


static bool	validData(std::string const& date, std::string const& value, bool input)
{
	return (validDate(date) && validPrice(value, input));
}




void	BitcoinExchange::parseData()
{
	std::ifstream	ifs("data.csv");
	if (!ifs)
	{
		std::cout << "Erreur : Le fichier ne peut pas etre ouvert" << std::endl;
		return;
	}
	std::string	line;
	std::getline(ifs, line);
	while (getline(ifs, line))
	{
		




	}
	ifs.close();
}










