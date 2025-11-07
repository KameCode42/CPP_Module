/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:05:51 by david             #+#    #+#             */
/*   Updated: 2025/11/07 10:06:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>//utiliser car iterable, acces par index
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

		//typedef crée un alias, c’est-à-dire un autre nom pour un type existant
		//container_type deque par defaut sinon peut etre vector,list...
		//iterator permet d utiliser iterator *it
		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;

		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"

#endif
