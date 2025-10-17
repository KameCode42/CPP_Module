/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:16:42 by david             #+#    #+#             */
/*   Updated: 2025/10/17 09:50:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

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
		unsigned int	size()const;\

		class	OutOfRange : public std::exception{
			public:
				virtual const char* what() const throw(){
					return ("Index hors de portee");
				}
		};

	private:
		T*				_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
