/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:03:10 by david             #+#    #+#             */
/*   Updated: 2025/07/25 14:34:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->_type = "Cat";
	std::cout << "Un animal de type " << this->_type << " est cree" << std::endl;
}

Cat::Cat(Cat const& src) : Animal(src){
}

Cat&	Cat::operator=(Cat const& other){
	if (this != &other){
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat est detruit" << std::endl;
}

void	Cat::makeSound()const{
	std::cout << this->_type << " Miaou !" << std::endl;
}

std::string	Cat::getType()const{
	return this->_type;
}
