/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:57:05 by david             #+#    #+#             */
/*   Updated: 2025/07/19 10:56:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "-------OBJET FRAGTRAP-------" << std::endl;
	std::cout << "FragTrap : " << name << " est cree" << std::endl;
	std::cout << "points de vie = " << this->_hitPoints << std::endl;
	std::cout << "points d'energie = " << this->_energyPoints << std::endl;
	std::cout << "degats d'attaque = " << this->_attackDamage << std::endl;
	std::cout << "competence speciale = high five" << std::endl;
	std::cout << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src){
}

FragTrap&	FragTrap::operator=(FragTrap const& other){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << this->_name << " est detruit" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap demande un high five ! Qui est partant ?" << std::endl;
}
