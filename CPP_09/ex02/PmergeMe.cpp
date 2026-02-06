/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:33:15 by david             #+#    #+#             */
/*   Updated: 2026/02/06 13:43:49 by david            ###   ########.fr       */
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

/*=== Parsing ===*/
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

/*==================================================================================*/
/*==================================================================================*/

/*=== Fonction Ford-Johnson pour vector ===*/

/*=== Construire les paires + dernier si impair ===*/
static void	makePairsVector(const std::vector<int>& input, std::vector< std::pair<int,int> >& pairs, bool& hasLast, int& last)
{
	pairs.clear();
	hasLast = false;
	last = 0;

	if (input.size() % 2 != 0){
		hasLast = true;
		last = input[input.size() - 1];
	}

	size_t i = 0;
	while (i + 1 < input.size())
	{
		int a = input[i];
		int b = input[i + 1];

		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
		i += 2;
	}
}

/*=== Trier les paires par leur max ===*/
static bool	comparePairBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

static void sortPairsByMax(std::vector< std::pair<int,int> >& pairs) {
	std::sort(pairs.begin(), pairs.end(), comparePairBySecond);
}

/*=== Construire la chaîne principale ===*/
static	std::vector<int> buildMainChain(const std::vector< std::pair<int,int> >& pairs)
{
	std::vector<int> mainChain;

	mainChain.push_back(pairs[0].first);

	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);

	return mainChain;
}

/*=== buildPendings, gerer les min en attente ===*/
static	std::vector<int> buildPendings(const std::vector< std::pair<int,int> >& pairs)
{
	std::vector<int> pendingChain;

	if (pairs.size() <= 1)
		return pendingChain;

	for (size_t i = 1; i < pairs.size(); i++)
		pendingChain.push_back(pairs[i].first);

	return pendingChain;
}

/*=== Creation de la suite de Jacobsthal ===*/
static	std::vector<size_t> jacobsthalSuite(size_t pendingSize)
{
	std::vector<size_t> jacob;

	size_t j0 = 0;
	size_t j1 = 1;

	while (j1 <= pendingSize)
	{
		if (jacob.empty() || j1 != jacob.back())
			jacob.push_back(j1);

		size_t j2 = j1 + (2 * j0);
		j0 = j1;
		j1 = j2;
	}
	return jacob;
}

/*=== Construire l’ordre final ===*/
static	std::vector<size_t> buildJacobOrder(size_t pendingSize)
{
	std::vector<size_t> jacob;
	std::vector<size_t> order;

	jacob = jacobsthalSuite(pendingSize);

	for (size_t i = 0; i < jacob.size(); i++)
		order.push_back(jacob[i]);

	size_t x;
	for (size_t j = 0; j < jacob.size() - 1; j++)
	{
		size_t a = jacob[j];
		size_t b = jacob[j + 1];

		x = b - 1;
		while (x > a)
		{
			order.push_back(x);
			x -= 1;
		}
	}

	size_t last = jacob.back();

	x = pendingSize;
	while (x > last)
	{
		order.push_back(x);
		x -= 1;
	}
	return order;
}











/*=== Algorithm Ford-Johnson ===*/
std::vector<int>	PmergeMe::fordJohnsonVector(std::vector<int> input)
{
	std::vector< std::pair<int,int> > pairs;
	bool hasLast = false;
	int last = 0;

	makePairsVector(input, pairs, hasLast, last);
	sortPairsByMax(pairs);
	//buildMainChain(pairs);

	return input;
}










/*==================================================================================*/
/*==================================================================================*/

/*=== Fonction principale run ===*/
void	PmergeMe::run()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _myVector.size(); i++)
		std::cout << _myVector[i] << " ";
	std::cout << std::endl;




	
	//temps de depart pour vector
	clock_t startVector = clock();//temps de debut
	_myVector = fordJohnsonVector(_myVector);
	clock_t endVector = clock();//temps de fin

	
	//pareil pour deque

	//afiche after
	std::cout << "After: ";
	for (size_t i = 0; i < _myVector.size(); i++)
		std::cout << _myVector[i] << " ";
	std::cout << std::endl;



	
	//caclul de temps

	//afficher temps
	double timeVector = (endVector - startVector) * 1000000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _myVector.size() << " elements with std::vector : " << timeVector << " us" << std::endl;
	
}
