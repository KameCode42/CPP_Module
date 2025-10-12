/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:12:27 by david             #+#    #+#             */
/*   Updated: 2025/10/12 09:59:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template<typename T>
void	iter(T *tab, size_t const& size, void (*func)(T&)){
	for (size_t i = 0; i < size; i++)
		func(tab[i]);
}

template<typename T>
void	iter(const T *tab, size_t const& size, void (*func)(const T&))
{
	for (size_t i = 0; i < size; i++)
		func(tab[i]);
}

#endif
