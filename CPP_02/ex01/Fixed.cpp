/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:26:47 by david             #+#    #+#             */
/*   Updated: 2025/07/03 19:22:59 by dle-fur          ###   ########.fr       */
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
	this->_value = roundf(f * (1 << bits));//f * 256
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

Fixed&	Fixed::operator=(Fixed const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& other, Fixed const& rhs){
	other << rhs.toFloat();
	return other;
}
