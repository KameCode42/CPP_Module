/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:12:31 by david             #+#    #+#             */
/*   Updated: 2025/07/20 17:54:01 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap : " << this->_name << " est cree" << std::endl;
	std::cout << "points de vie = " << this->_hitPoints << std::endl;
	std::cout << "points d'energie = " << this->_energyPoints << std::endl;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage){
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& other){
	if (this != &other){
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << this->_name << " Clap est detruit" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints == 0){
		std::cout << this->_name << " ne peut pas attaquer" << std::endl;
		std::cout << "point de vie = " << this->_hitPoints << std::endl;
		std::cout << "point d'energie = " << this->_energyPoints << std::endl;
		return;
	}
	std::cout << this->_name << " attaque " << target << " causant " << this->_attackDamage << " de degats" << std::endl;
	this->_energyPoints -= 1;
	std::cout << "points d'energie actuel = " << this->_energyPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	this->_hitPoints -= amount;
	std::cout << this->_name << " prend des degats" << std::endl;
	std::cout << this->_name << " perd " << amount << " points de vie" << std::endl;
	std::cout << "points de vie actuel = " << this->_hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	std::cout << this->_name << " se repare" << std::endl;
	this->_hitPoints += amount;
	std::cout << this->_name << " a regagner " << amount << " points de vie" << std::endl;
	std::cout << "points de vie actuel = " << this->_hitPoints << std::endl;
	this->_energyPoints -= 1;
	std::cout << "points d'energie actuel = " << this->_energyPoints << std::endl;
}
