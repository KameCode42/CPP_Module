/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:15:07 by david             #+#    #+#             */
/*   Updated: 2025/07/24 17:16:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong Animal"){
	std::cout << this->_type << " est cree" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src) : _type(src._type){
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& other){
	if (this != &other){
		this->_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << this->_type << " est detruit" << std::endl;
}

void	WrongAnimal::makeSound()const{
	std::cout << this->_type << " emet un son grave" << std::endl;
}

std::string	WrongAnimal::getType()const{
	return this->_type;
}
