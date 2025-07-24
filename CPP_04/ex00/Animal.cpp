/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:19:15 by david             #+#    #+#             */
/*   Updated: 2025/07/24 16:59:50 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << this->_type << " est cree" << std::endl;
}

Animal::Animal(Animal const& src) : _type(src._type){
}

Animal&	Animal::operator=(Animal const& other){
	if (this != &other){
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal est detruit" << std::endl;
}

void	Animal::makeSound()const{
	std::cout << this->_type << " emet un son generique" << std::endl;
}

std::string	Animal::getType()const{
	return this->_type;
}