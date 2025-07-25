/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:22:05 by dle-fur           #+#    #+#             */
/*   Updated: 2025/07/25 16:40:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	const ne peut pas etre reassignes
	pour copier une const, detruire les instances avec le destructeur
	recreer les instances a partir de other sur emplacement memoire de this
*/

Point::Point() : _x(0), _y(0){
}

Point::Point(const float x, const float y) : _x(x), _y(y){
}

Point::Point(Point const& src) : _x(src._x), _y(src._y){
}

Point&	Point::operator=(Point const& other){
	if (this != &other){
		this->~Point();
		new(this)Point(other);
	}
	return *this;
}

Point::~Point(){
}

std::ostream&	operator<<(std::ostream& os, Point const& point){
	os << point.getX() << point.getY();
	return os;
}

Fixed const	Point::getX()const{
	return this->_x;
}

Fixed const	Point::getY()const{
	return this->_y;
}
