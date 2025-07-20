/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:22:50 by david             #+#    #+#             */
/*   Updated: 2025/07/20 18:04:10 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->ScavTrap::_attackDamage = 30;
	std::cout << "DiamondTrap : " << name << " est cree" << std::endl;
	std::cout << "points de vie = " << this->_hitPoints << std::endl;
	std::cout << "points d'energie = " << this->_energyPoints << std::endl;
	std::cout << "degats d'attaque = " << this->_attackDamage << std::endl;
	std::cout << "competence speciale = who am i" << std::endl;
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src), ScavTrap(src), FragTrap(src){
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& other){
	if (this != &other){
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << this->_name << " Diam est detruit" << std::endl;
}

void	DiamondTrap::whoAmI(){
	std::cout << "competence speciale lancee" << std::endl;
	std::cout << "je m'appelle " << this->_name << " et j'ai detruit " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}
