/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:32:54 by david             #+#    #+#             */
/*   Updated: 2025/10/09 17:09:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Utilisation de reinterpret_cast :
- permet le retypage de ptr ou ref sans perdre de donnees
*/

#include "Serialize.hpp"

int	main(){
	Data		original;
	uintptr_t	serialized;
	Data*		deserialized;

	original.nbr = 42;
	original.str = "hello";

	std::cout << "Sans cast : " << std::endl;
	std::cout << "Nombre : " << original.nbr << std::endl;
	std::cout << "Adresse nombre : " << &original.nbr << std::endl;
	std::cout << "String : " << original.str << std::endl;
	std::cout << "Adresse string : " << &original.str << std::endl;
	std::cout << std::endl;

	serialized = Serialize::serialize(&original);
	deserialized = Serialize::deserialize(serialized);

	std::cout << "Avec cast : " << std::endl;
	std::cout << "Nombre : " << deserialized->nbr << std::endl;
	std::cout << "Adresse nombre : " << &deserialized->nbr << std::endl;
	std::cout << "String : " << deserialized->str << std::endl;
	std::cout << "Adresse string : " << &deserialized->str << std::endl;
	return 0;
}
