/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:08:37 by david             #+#    #+#             */
/*   Updated: 2025/10/25 15:43:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_array.size() = combien de nombres sont stocker
	distance = combien de nombres a ajouter
	_maxSize = la capacité maximale du Span
	_array.size() + distance > _maxSize	verifie si depassement de la limite
*/

#ifndef SPAN_TPP
# define SPAN_TPP

#include "Span.hpp"

template<typename T>
void	Span::addNumber(T first, T last){
	size_t	distance = std::distance(first, last);

	if (_array.size() + distance > _maxSize)
		throw ErrorFull();
	_array.insert(_array.end(), first, last);
}

#endif
