/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:56:13 by david             #+#    #+#             */
/*   Updated: 2025/06/22 11:52:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
};

Weapon::Weapon(const std::string& type){
	this->_type = type;
}

Weapon::~Weapon(){
};

void	Weapon::setType(const std::string& type){
	this->_type = type;
}

const std::string&	Weapon::getType()const{
	return this->_type;
}
