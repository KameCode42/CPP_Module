/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:03:10 by david             #+#    #+#             */
/*   Updated: 2025/08/08 14:18:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->_type = "Cat";
	_brain = new Brain();
	std::cout << "Un animal de type " << this->_type << " est cree" << std::endl;
}

Cat::Cat(Cat const& src) : Animal(src){
	_brain = new Brain(*src._brain);
}

Cat&	Cat::operator=(Cat const& other){
	if (this != &other){
		Animal::operator=(other);
		if (_brain == NULL)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat(){
	delete _brain;
	std::cout << "Cat est detruit" << std::endl;
}

void	Cat::makeSound()const{
	std::cout << this->_type << " Miaou !" << std::endl;
}

std::string	Cat::getType()const{
	return this->_type;
}

Brain	*Cat::getBrain(){
	return this->_brain;
}