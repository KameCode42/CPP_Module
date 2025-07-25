/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:37:50 by david             #+#    #+#             */
/*   Updated: 2025/07/25 14:35:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->_type = "Dog";
	std::cout << "Un animal de type " << this->_type << " est cree" << std::endl;
}

Dog::Dog(Dog const& src) : Animal(src){
}

Dog&	Dog::operator=(Dog const& other){
	if (this != &other){
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog est detruit" << std::endl;
}

void	Dog::makeSound()const{
	std::cout << this->_type << " Waouf !" << std::endl;
}

std::string	Dog::getType()const{
	return this->_type;
}
