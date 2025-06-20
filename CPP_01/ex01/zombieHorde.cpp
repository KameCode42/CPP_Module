/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:19:56 by david             #+#    #+#             */
/*   Updated: 2025/06/20 18:19:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	if (name.empty()){
		std::cout << "Error: the string must not be empty" << std::endl;
		return NULL;
	}
	if (N < 1){
		std::cout << "Error: invalid entry" << std::endl;
		return NULL;
	}
	Zombie	*horde = new Zombie[N];
	std::cout << "A horde of " << N << " zombies was created" << std::endl;
	for (int i = 0; i < N; i++){
		horde[i].setName(name);
		horde[i].announce();
	}
	return horde;
}
