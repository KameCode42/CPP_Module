/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:45:30 by david             #+#    #+#             */
/*   Updated: 2025/11/14 11:20:00 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdlib>

class	Span
{
	public:
		Span(unsigned int n);
		Span(Span const& src);
		Span&	operator=(Span const& other);
		~Span();
	
		void	addNumber(unsigned int n);
		int		shortestSpan();
		int		longestSpan();

		template<typename T>
		void	addNumber(T begin, T end);

		class	ErrorFull : public std::exception{
			virtual const char* what() const throw();
		};

		class	ErrorStorage : public std::exception{
			virtual const char* what() const throw();
		};

	private:
		std::vector<int>	_array;
		unsigned int		_maxSize;
};

#include "Span.tpp"

#endif
