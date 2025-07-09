/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:26:47 by david             #+#    #+#             */
/*   Updated: 2025/07/09 17:46:29 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------------Constructeur-----------------*/

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << Fixed::bits;
}

Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << bits));
}

/*-----------------Destructeur------------------*/

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

/*--------------------Membre--------------------*/

int	Fixed::getRawBits(void)const{
	return this->_value;
}

void	Fixed::setRawBits(int const raw){
	this->_value = raw;
}

int	Fixed::toInt(void)const{
	return this->_value >> Fixed::bits;
}

float	Fixed::toFloat(void)const{
	return (float)(this->_value) / (1 << bits);
}

/*--------------------Operator--------------------*/

Fixed&	Fixed::operator=(Fixed const& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed){
	os << fixed.toFloat();
	return os;
}
