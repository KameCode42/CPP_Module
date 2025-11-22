/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:25:56 by david             #+#    #+#             */
/*   Updated: 2025/11/22 17:42:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Etape validDate:
- check l annee
- check le mois
- check le jour
- check si bisextil

Etape validPrice:
- check si vide ou commence par .
- trouve le nombre de . (min 1)
- trouve le point
- check si une sous chaine existe (10.22 ou 10)
- check si digit before et after
- cast la value en double
- check de verification

Etape parseData:
- check ouverture fichier
- passe la premiere ligne
- pour chaque ligne :
- trouve la virgule et extrait chaine
- si une sous chaine est trouver -> prend la valeur
- si valide data est ok -> cast en double price
- et ajoute dans std::map
*/

/*
//bisextil = 29 jours = tous les 4 ans
// regle : (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)
//exemple : 2024 % 4 = 0 ok, 2024 % 100 = 20,24 reste 24 donc != 0 donc bisextil
*/

#include "BitcoinExchange.hpp"

/*=== Constructeur ===*/

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) : _price(src._price) {};

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& other) {
	if (this != &other) {
		_price = other._price;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {};

/*==================================================================================*/

/*=== Fonction fichier data.csv ===*/

static int	checkDate(std::string const& first)
{
	for (int i = 0; i < first.size(); i++) {
		if (!std::isdigit(first[i]))
			return -1;
	}
	int date = std::atoi(first.c_str());
	return date;
}

static bool	validDate(std::string const& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string y = date.substr(0, 4);
	std::string m = date.substr(5, 2);
	std::string d = date.substr(8, 2);

	int year = checkDate(y);
	if (year < 2009)
		return false;
	if (year == -1)
		return false;

	int month = checkDate(m);
	if (month == -1)
		return false;
	if (month < 1 || month > 12)
		return false;

	int maxDays = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDays = 30;
	else
		maxDays = 31;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			maxDays = 29;
		else
			maxDays = 28;
	}
	
	int day = checkDate(d);
	if (day == -1)
		return false;
	if (day < 1 || day > maxDays)
		return false;

	return true;
}

static bool	validPrice(std::string const& value)
{
	size_t	i = 0;

	if (value.empty() || value[0] == '.')
		return false;

	if (std::count(value.begin(), value.end(), '.') > 1)
		return false;

	size_t point = value.find('.');
	std::string	beforePoint;
	std::string	afterPoint;

	if (point != std::string::npos) {
		beforePoint = value.substr(i, point - i);
		afterPoint = value.substr(point + 1);
	}
	else {
		beforePoint = value;
		afterPoint = "";
	}

	for (size_t j = 0; j < beforePoint.size(); j++) {
		if (!std::isdigit(beforePoint[j]))
			return false;
	}

	for (size_t j = 0; j < afterPoint.size(); j++) {
		if (!std::isdigit(afterPoint[j]))
			return false;
	}

	return true;
}

static bool	validData(std::string const& date, std::string const& value)
{
	return (validDate(date) && validPrice(value));
}

void	BitcoinExchange::parseData(std::string const& filename)
{
	std::ifstream ifs(filename);

	if (!ifs) {
		std::cout << "Erreur : Le fichier ne peut pas etre ouvert" << std::endl;
		return;
	}

	std::string	line;
	std::getline(ifs, line);

	while (getline(ifs, line))
	{
		size_t pos = line.find(',');
		std::string date = line.substr(0, pos);
		std::string value;
		if (pos != std::string::npos)
			value = line.substr(pos + 1);

		if (validData(date, value)) {
			double price = strtod(value.c_str(), NULL);
			_price[date] = price;
		}
	}
	ifs.close();
}

/*==================================================================================*/

/*=== Fonction fichier input ===*/

void	BitcoinExchange::parseInput(std::string const& filename)
{
	std::ifstream	ifs(filename);

	if (!ifs) {
		std::cout << "Erreur : Le fichier ne peut pas etre ouvert" << std::endl;
		return;
	}

	std::string	line;
	std::getline(ifs, line);

	while (getline(ifs, line))
	{
		if (line.empty())
			continue;

		size_t pos = line.find('|');
		if (pos == std::string::npos) {
			std::cout << "Erreur : pas de '|'" << std::endl;
			continue;
		}

		std::string	date = line.substr(0, pos);
		std::string	value;

		if (pos != std::string::npos)
			value = line.substr(pos + 1);
		else {
			std::cout << "valeur ne dois pas etre vide" << std::endl;
			continue;
		}

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);

		value.erase(0, value.find_first_not_of(" \t"));
		value.erase(value.find_last_not_of(" \t") + 1);
		
		if (validData(date, value, true))
		{
			double	price = strtod(value.c_str(), NULL);
			if (price < 0) {
				std::cout << "Error: not a positive number" << std::endl;
				continue;
			}
			if (price > 1000) {
				std::cout << "Error: too large a number" << std::endl;
				continue;
			}
			std::map<std::string, double>::iterator it = _price.lower_bound(date);
			if (it == _price.begin() && date < it->first) {
				std::cout << "Erreur : aucune donnée avant cette date" << std::endl;
				continue;
			}
			double result;
			if (it != _price.end() && it->first == date)
				result = it->second * price;
			else
				--it;
			std::cout << date << " => " << price << " = " << result << std::endl;
		}
		else {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
	}
}
