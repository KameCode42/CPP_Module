/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:10:57 by david             #+#    #+#             */
/*   Updated: 2026/02/05 17:04:23 by david            ###   ########.fr       */
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

/*=== Fonction Ford-Johnson pour vector ===*/

//Construire les paires + straggler
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

/*==================================================================================*/

//Trier les paires par leur max
static bool	comparePairBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

static void sortPairsByMax(std::vector< std::pair<int,int> >& pairs) {
	std::sort(pairs.begin(), pairs.end(), comparePairBySecond);
}

/*==================================================================================*/

//Construire la chaîne principale
static	std::vector<int> buildMainChain(const std::vector< std::pair<int,int> >& pairs)
{
	std::vector<int> mainChain;

	mainChain.push_back(pairs[0].first);

	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);

	return mainChain;
}

/*==================================================================================*/

//buildPendings, insertion des min en attente
static	std::vector<int> buildPendings(const std::vector< std::pair<int,int> >& pairs)
{
	std::vector<int> pendingChain;

	if (pendingChain.size() <= 1)
		return pendingChain;

	for (size_t i = 1; i < pendingChain.size(); i++)
		pendingChain.push_back(pairs[i].first);

	return pendingChain;
}

/*==================================================================================*/

//Creation de la suite de Jacobsthal
static	std::vector<size_t> jacobsthalSuite(size_t m)
{
	std::vector<size_t> jacob;

	size_t j0 = 0;
	size_t j1 = 1;

	while (j1 <= m)
	{
		if (jacob.empty() || j1 != jacob.back())
			jacob.push_back(j1);

		size_t j2 = j1 + (2 * j0);
		j0 = j1;
		j1 = j2;
	}
	return jacob;
}

/*==================================================================================*/

//Construire l’ordre final
static	std::vector<size_t> buildJacobOrder(size_t m)
{
	std::vector<size_t> jacob;
	std::vector<size_t> order;

	jacob = jacobsthalSuite(m);

	for (size_t j = 0; j < jacob.size(); j++)
	{
		order.push_back(jacob[j]);
	}
	
}





std::vector<int>	PmergeMe::fordJohnsonVector(std::vector<int> input)
{
	std::vector< std::pair<int,int> > pairs;
	bool hasLast = false;
	int last = 0;

	makePairsVector(input, pairs, hasLast, last);
	sortPairsByMax(pairs);
	buildMainChain(pairs);

	return input;
}







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

























/*==================================================================================*/
/*==================================================================================*/

/*=== Note ===*/
/*
==================================================================================
parseLine: ./a.out 34 4 66
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

==================================================================================
makePairsVector: Creer des pairs pour reperer les min, max
Si la taille est impair, met le dernier nombre de coter
Boucle sur la taille de input
Copie les valeurs i et i + 1 afin de les comparer
Push dans le container pairs selon le min des pairs former
Avance de i + 2
==================================================================================

==================================================================================
sortPairsByMax: Trier les paires par leur max
Compare le max du second de la pair et la trie
==================================================================================

==================================================================================
buildMainChain: Construire la chaîne principale
Creer un vector local
push le premier nbr de la pair -> il sera de toute maniere le plus petit
push tous les second trier par leur max
==================================================================================

==================================================================================
jacobsthalSuite: Creation de la suite afin d'utiliser les idx jacob pour insertion
Vrai suite jacob : 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365,...
-
m = pending.size()
Creer un vector local jacob, contiendra les index a utiliser pour l'insertion
push j1 dans jacob car utile
jacob = 1
j2 = 1 + (2 * 0), j2 = 1
j0 = 1
j1 = 1
push j1
jacob = 1 1
j3 = 1 + (2 * 1), j3 = 3
j0 = 1
j1 = 3
push j3
jacob = 1 1 3
return jacob = index du vector pending
si pending = 12 34 55
12 = 1
34 = 1
55 = 3

le 1 n'est pas utiliser 2 fois donc en insertion : 1,3 ensuite le 2
pending[0] = 12 = 1
pending[2] = 55 = 3
pending[1] = 34 = 2
donc on insert le 12 , 55, 34
==================================================================================








==================================================================================
fordJohnsonVector:
Contenu input = 18, 9, 34, 100, 22, 12
-
makePairsVector:
Contenu pairs = (9,18) (34,100) (12,22)
-
sortPairsByMax:
Contenu pairs = (9,18) (12,22) (34,100)
-
buildMainChain:
Contenu mainChain = 9, 18, 22, 100
==================================================================================
*/
