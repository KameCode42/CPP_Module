/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:52:02 by david             #+#    #+#             */
/*   Updated: 2025/10/25 15:00:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _array(){
}

Span::Span(Span const& src) : _maxSize(src._maxSize), _array(src._array){
}

Span&	Span::operator=(Span const& other){
	if (this != &other){
		_maxSize = other._maxSize;
		_array = other._array;
	}
	return *this;
}

Span::~Span(){
}

void	Span::addNumber(unsigned int n){
	if (_array.size() >= _maxSize)
		throw ErrorFull();
	_array.push_back(n);
}

int	Span::shortestSpan(){
	if (_array.size() < 2)
		throw ErrorStorage();
	
	std::sort(_array.begin(), _array.end());
	std::vector<int>::iterator it = _array.begin();

	int shortSpan = _array[1] - _array[0];
	while (it != _array.end() - 1)
	{
		if (*it < *(it + 1)){
			int difference = *(it + 1) - *it;
			if (difference < shortSpan)
				shortSpan = difference;
		}
		it++;
	}
	return shortSpan;
}

int	Span::longestSpan(){
	if (_array.size() < 2)
		throw ErrorStorage();

	std::vector<int>::iterator itMin = std::min_element(_array.begin(), _array.end());
	std::vector<int>::iterator itMax = std::max_element(_array.begin(), _array.end());

	int longSpan = *itMax - *itMin;

	return longSpan;
}
