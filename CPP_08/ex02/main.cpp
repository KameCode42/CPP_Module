/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:04:57 by david             #+#    #+#             */
/*   Updated: 2025/11/07 10:34:07 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main()
{
	system("clear");

	std::cout << "\n=== Test Sujet ===" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Taille de la pile apres push : " << mstack.size() << std::endl;
	std::cout << "Element superieur de la pile : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Taille de la pile apres pop : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Taille de la pile apres push : " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Contenu de la pile : " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "Copie de MutantStack dans une pile standard stack" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Taille de la pile : " << s.size() << std::endl;
	std::cout << std::endl;

	/*-----------------------------------------------------------------------------*/

	std::cout << "\n=== Test std::list ===" << std::endl;

	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Taille de la pile apres push : " << lst.size() << std::endl;
	std::cout << "Dernier element ajouter dans la list : " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Taille de la pile apres pop_back : " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::cout << "Taille de la pile apres push : " << lst.size() << std::endl;
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	std::cout << "Contenu de la list : " << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::cout << std::endl;
	return 0;
}
