/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:00:55 by david             #+#    #+#             */
/*   Updated: 2025/06/20 10:57:48 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_name = name;
	std::cout << "The zombie " << this->_name << " is created" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << "The zombie " << this->_name << " is destroyed" << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
