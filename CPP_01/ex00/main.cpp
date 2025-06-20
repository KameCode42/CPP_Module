/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:00:42 by david             #+#    #+#             */
/*   Updated: 2025/06/20 11:27:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){
	Zombie	*z = NULL;

	std::cout << "-----------stack-----------" << std::endl;
	randomChump("ratchet");
	std::cout << std::endl;
	std::cout << "-----------heap------------" << std::endl;
	z = newZombie("clank");
	delete z;
	return 0;
}
