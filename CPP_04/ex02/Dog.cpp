/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:37:50 by david             #+#    #+#             */
/*   Updated: 2025/08/08 14:17:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->_type = "Dog";
	_brain = new Brain();
	std::cout << "Un animal de type " << this->_type << " est cree" << std::endl;
}

Dog::Dog(Dog const& src) : Animal(src){
	_brain = new Brain(*src._brain);
}

Dog&	Dog::operator=(Dog const& other){
	if (this != &other){
		Animal::operator=(other);
		if (_brain == NULL)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog(){
	delete _brain;
	std::cout << "Dog est detruit" << std::endl;
}

void	Dog::makeSound()const{
	std::cout << this->_type << " Waouf !" << std::endl;
}

std::string	Dog::getType()const{
	return this->_type;
}

Brain	*Dog::getBrain(){
	return this->_brain;
}