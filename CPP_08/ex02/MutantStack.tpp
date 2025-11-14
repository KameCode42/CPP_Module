/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:37:17 by david             #+#    #+#             */
/*   Updated: 2025/11/14 11:22:23 by dle-fur          ###   ########.fr       */
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
