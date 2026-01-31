/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:10:57 by david             #+#    #+#             */
/*   Updated: 2026/01/31 14:15:40 by david            ###   ########.fr       */
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

int	PmergeMe::parse(int argc, char **argv)
{
	std::vector<int>	tmp_vector;
	std::deque<int>		tmp_deque;

	for (int i = 1; i < argc; i++)
	{
		std::string number(argv[i]);

		for (size_t j = 0; j < number.size(); j++)
		{
			if (!std::isdigit(number[j])) {
				std::cerr << "Erreur" << std::endl;
				return 1;
			}
		}

		std::istringstream iss(number);
		long value;

		iss >> value;

		if (iss.fail() || value <= 0 || value > INT_MAX) {
			std::cerr << "Erreur" << std::endl;
			return 1;
		}

		int nbr = static_cast<int>(value);

		if (std::find(tmp_vector.begin(), tmp_vector.end(), nbr) != tmp_vector.end()) {
			std::cerr << "Erreur" << std::endl;
			return 1;
		}

		tmp_deque.push_back(nbr);
		tmp_vector.push_back(nbr);
	}

	_myDeque = tmp_deque;
	_myVector = tmp_vector;

	return 0;
}








void	PmergeMe::run()
{
	std::cout << "Before : ";
	for (size_t i = 0; i < _myVector.size(); i++)
		std::cout << _myVector[i] << " ";
	std::cout << std::endl;
}

























/*==================================================================================*/
/*==================================================================================*/

/*=== Note ===*/
/*
==================================================================================
parseLine : ./a.out 34 4 66
Creer deux containers local temporaire
Boucle sur argc -> prend le premier nbr(argv[0])
Affecte dans une string pour parcourir un nbr comme -> 34
Check si 3 et 4 sont des digit, si oui -> erreur
Extrait le premier nbr et check si negatif ou > a INT_MAX
Cast long en int
Check si les containers contiennent des doublons
Push dans les containers temporaire jusqu a la fin du parsing
Une fois tout ok, copie le contenu dans les vrai containers
==================================================================================
*/
