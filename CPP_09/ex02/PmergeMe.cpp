/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:10:57 by david             #+#    #+#             */
/*   Updated: 2026/01/31 11:05:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*=== Constructeur ===*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) : _myDeque(src._myDeque), _myVector(src._myVector) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_myDeque = other._myDeque;
		_myVector = other._myVector;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

/*==================================================================================*/

/*=== Fonction membre ===*/

int	PmergeMe::parseLine(const std::string& line)
{
	std::istringstream iss(line);
	long value;
	bool  number = false;

	while (iss >> value)
	{
		number = true;
		if (value < 0 || value > INT_MAX) {
			std::cout << "Erreur : nombre negatif ou > a INT_MAX" << std::endl;
			return 1;
		}

		int nbr = static_cast<int>(value);

		if (std::find(_myVector.begin(), _myVector.end(), nbr) != _myVector.end()) {
			std::cout << "Erreur : doublon trouver" << std::endl;
			return 1;
		}

		_myDeque.push_back(nbr);
		_myVector.push_back(nbr);
	}

	if (!number) {
		std::cout << "Erreur : aucun nombre a traiter" << std::endl;
		return 1;
	}

	if (iss.fail() && !iss.eof()) {
		std::cout << "Erreur" << std::endl;
		return 1;
	}
	
	return 0;
}


















/*==================================================================================*/
/*==================================================================================*/

/*=== Note ===*/
/*
==================================================================================
parseLine : ./a.out "34 4 67"
Extrait le premier entier -> 34
Check si negatif ou superieur a INT_MAX
Si ok, cast long en int
Check si les containers ne contiennet pas de doublon
Push dans les deux containers le nombre
Si aucun nombre a traiter -> erreur (./a.out "", "-", "a") = false
Si un token est faux ou si le fichier n a pas fini la lecture -> erreur (fail et eof)
==================================================================================
*/
