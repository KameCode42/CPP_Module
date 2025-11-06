/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:37:17 by david             #+#    #+#             */
/*   Updated: 2025/11/06 17:24:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& src) : std::stack<T>(src){
}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const& other){
	if (this != &other){
		std::stack<T>::operator=(other);
	}
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(){
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(){
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(){
	return this->c.end();
}

#endif
