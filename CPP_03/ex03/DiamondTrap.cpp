/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:21:19 by david             #+#    #+#             */
/*   Updated: 2025/07/19 13:40:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "-------OBJET DIAMONTRAP-------" << std::endl;
	std::cout << "DiamondTrap : " << this->_name << " est cree" << std::endl;
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
	std::cout << this->_name << " est detruit" << std::endl;
}

void	DiamondTrap::whoAmI(){
	std::cout << "nom du DiamondTrap : " << this->_name << std::endl;
	std::cout << "nom du ClapTrap : " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}