/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:09:32 by david             #+#    #+#             */
/*   Updated: 2025/06/22 14:59:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
	this->_weapon = NULL;
}

HumanB::~HumanB(){
}

void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (!this->_weapon)
		std::cout << this->_name << " doesn't have a weapon " << std::endl;
	else
		std::cout << this->_name << " attack with " << this->_weapon->getType() << std::endl;
}
