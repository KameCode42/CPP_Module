/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:33:48 by david             #+#    #+#             */
/*   Updated: 2025/07/25 09:10:27 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->_type = "Wrong Cat";
	std::cout << "Un animal de type " << this->_type << " est cree" << std::endl;
}

WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src){
}

WrongCat&	WrongCat::operator=(WrongCat const& other){
	if (this != &other){
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << this->_type << " est detruit" << std::endl;
}

void	WrongCat::makeSound()const{
	std::cout << this->_type << " Grrrrrr !" << std::endl;
}

std::string	WrongCat::getType()const{
	return this->_type;
}
