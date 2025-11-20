/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:05:51 by david             #+#    #+#             */
/*   Updated: 2025/11/20 14:48:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
deque : utiliser car iterable, acces par index
typedef : alias, autre nom pour un type existant
container_type : container interne utiliser
iterator : pour utiliser iterator begin,end
*/

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <cstdlib>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(MutantStack const& src);
		MutantStack&	operator=(MutantStack const& other);
		~MutantStack();

		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;

		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"

#endif
