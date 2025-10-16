/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:16:42 by david             #+#    #+#             */
/*   Updated: 2025/10/16 16:37:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class	Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const& src);
		Array&	operator=(Array const& other);
		~Array();

		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;

		unsigned int	size()const;

	private:
		T*				_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
