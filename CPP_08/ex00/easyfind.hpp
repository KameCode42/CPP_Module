/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:21:51 by david             #+#    #+#             */
/*   Updated: 2025/11/14 11:09:57 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

class	ErrorFind : public std::exception
{
	public:
		virtual const char* what() const throw();
};

template<typename T>
int	easyfind(const T& array, int value);

#include "easyfind.tpp"

#endif
