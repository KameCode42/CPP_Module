/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:22:00 by david             #+#    #+#             */
/*   Updated: 2025/10/17 14:34:20 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T>
int	easyfind(const T& array, int value)
{
	typename T::const_iterator	it;
	typename T::const_iterator	ite = array.cend();

	for (it = array.cbegin(); it != ite; it++){
		if (*it == value){
			std::cout << "Occurence trouvee : " << *it << std::endl;
			return *it;
		}
	}
	throw ErrorFind();
}

#endif
