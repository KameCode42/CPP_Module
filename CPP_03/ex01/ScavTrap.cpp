/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:24:32 by david             #+#    #+#             */
/*   Updated: 2025/07/20 18:05:41 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap : " << name << " est cree" << std::endl;
	std::cout << "points de vie = " << this->_hitPoints << std::endl;
	std::cout << "points d'energie = " << this->_energyPoints << std::endl;
	std::cout << "degats d'attaque = " << this->_attackDamage << std::endl;
	std::cout << "competence speciale = Gate keeper" << std::endl;
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
	std::cout << this->_name << " Scav est detruit" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << "competence speciale lancee" << std::endl;
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
