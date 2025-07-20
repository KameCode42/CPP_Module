/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:57:05 by david             #+#    #+#             */
/*   Updated: 2025/07/20 10:35:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
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
