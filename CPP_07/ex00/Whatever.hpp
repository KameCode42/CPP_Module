/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:59:41 by david             #+#    #+#             */
/*   Updated: 2025/10/11 11:50:55 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &a, T &b){
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T &a, T &b){
	if (a == b)
		return b;
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
T	max(T &a, T &b){
	if (a == b)
		return b;
	if (a > b)
		return a;
	else
		return b;
}

#endif
