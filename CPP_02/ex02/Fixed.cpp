/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:31:36 by david             #+#    #+#             */
/*   Updated: 2025/07/05 16:45:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------------Constructeur-----------------*/

Fixed::Fixed() : _value(0){
}

Fixed::Fixed(Fixed const& src){
	*this = src;
}

Fixed::Fixed(const int n){
	this->_value = n << Fixed::bits;
}

Fixed::Fixed(const float f){
	this->_value = roundf(f * (1 << bits));
}

/*-----------------Destructeur------------------*/

Fixed::~Fixed(){
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

/*--------------------opérateurs arithmétiques--------------------*/

Fixed	Fixed::operator+(Fixed const& src)const{
	float	result;
	result = this->toFloat() + src.toFloat();
	return result;
}

Fixed	Fixed::operator-(Fixed const& src)const{
	float	result;
	result = this->toFloat() - src.toFloat();
	return result;
}

Fixed	Fixed::operator*(Fixed const& src)const{
	float	result;
	result = this->toFloat() * src.toFloat();
	return result;
}

Fixed	Fixed::operator/(Fixed const& src)const{
	float	result;
	result = this->toFloat() / src.toFloat();
	return result;
}

/*--------------------opérateurs d’incrémentation et de décrémentation--------------------*/

Fixed&	Fixed::operator++(){
	++this->_value;
	return *this;// return new value by reference
}

Fixed	Fixed::operator++(int){
	Fixed	old = *this;
	operator++();
	return old;
}

Fixed&	Fixed::operator--(){
	--this->_value;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	old = *this;
	operator--();
	return old;
}

/*--------------------opérateur de comparaison--------------------*/

bool	Fixed::operator>(Fixed const& src)const{
	if (this->_value > src._value)
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const& src)const{
	if (this->_value < src._value)
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const& src)const{
	if (this->_value >= src._value)
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const& src)const{
	if (this->_value <= src._value)
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const& src)const{
	if (this->_value == src._value)
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const& src)const{
	if (this->_value != src._value)
		return true;
	return false;
}

/*--------------------opérateur d’affectation--------------------*/

Fixed&	Fixed::operator=(Fixed const& src){
	this->_value = src.getRawBits();
	return *this;
}

/*--------------------opérateur d'insertion--------------------*/

std::ostream&	operator<<(std::ostream& os, Fixed const& other){
	os << other.toFloat();
	return os;
}