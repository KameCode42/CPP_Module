/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:57:05 by david             #+#    #+#             */
/*   Updated: 2025/07/20 18:05:01 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
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
	std::cout << this->_name << " Frag est detruit" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "competence speciale lancee" << std::endl;
	std::cout << "FragTrap demande un high five ! Qui est partant ?" << std::endl;
}
