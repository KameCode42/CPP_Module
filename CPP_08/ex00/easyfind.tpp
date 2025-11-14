/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:22:00 by david             #+#    #+#             */
/*   Updated: 2025/11/14 11:17:58 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T>
int	easyfind(const T& array, int value)
{
	typename T::const_iterator	it = std::find(array.cbegin(), array.cend(), value);

	if (it != array.cend()){
		std::cout << "Occurence trouvee : " << *it << std::endl;
		return *it;
	}
	throw ErrorFind();
}

const char* ErrorFind::what() const throw(){
	return ("aucune occurrence");
}

#endif
