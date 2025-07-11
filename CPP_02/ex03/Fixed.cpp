/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:18:02 by dle-fur           #+#    #+#             */
/*   Updated: 2025/07/11 09:18:07 by dle-fur          ###   ########.fr       */
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

Fixed	Fixed::operator+(Fixed const& other)const{
	Fixed	result;
	result._value = this->_value + other._value;
	return result;
}

Fixed	Fixed::operator-(Fixed const& other)const{
	Fixed	result;
	result._value = this->_value - other._value;
	return result;
}

Fixed	Fixed::operator*(Fixed const& other)const{
	float result = this->toFloat() * other.toFloat();
	return Fixed(result);
}

Fixed	Fixed::operator/(Fixed const& other)const{
	if (other.toFloat() == 0){
		std::cout << "erreur: division par 0 impossible" << std::endl;
		return Fixed(0);
	}
	float result = this->toFloat() / other.toFloat();
	return Fixed(result);
}

/*--------------------opérateurs d’incrémentation et de décrémentation--------------------*/

Fixed&	Fixed::operator++(){
	++this->_value;
	return *this;
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

bool	Fixed::operator>(Fixed const& other)const{
	if (this->_value > other._value)
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const& other)const{
	if (this->_value < other._value)
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const& other)const{
	if (this->_value >= other._value)
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const& other)const{
	if (this->_value <= other._value)
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const& other)const{
	if (this->_value == other._value)
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const& other)const{
	if (this->_value != other._value)
		return true;
	return false;
}

/*--------------------opérateur d’affectation--------------------*/

Fixed&	Fixed::operator=(Fixed const& other){
	if (this != &other)
		this->_value = other._value;
	return *this;
}

/*--------------------opérateur d'insertion--------------------*/

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed){
	os << fixed.toFloat();
	return os;
}
