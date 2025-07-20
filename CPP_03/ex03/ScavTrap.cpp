/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:24:32 by david             #+#    #+#             */
/*   Updated: 2025/07/20 10:35:09 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Scavtrap constructor called" << std::endl;
	std::cout << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src){
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& other){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << this->_name << " est detruit" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << this->_name << " est en mode : Gate keeper" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (this->_hitPoints <= 0 || this->_energyPoints == 0){
		std::cout << this->_name << " ne peut pas attaquer" << std::endl;
		std::cout << "point de vie = " << this->_hitPoints << std::endl;
		std::cout << "point d'energie = " << this->_energyPoints << std::endl;
		return;
	}
	std::cout << this->_name << " attaque avec une boule de feu " << target << " causant " << this->_attackDamage << " de degats" << std::endl;
	this->_energyPoints -= 1;
	std::cout << "points d'energie actuel = " << this->_energyPoints << std::endl;
}
