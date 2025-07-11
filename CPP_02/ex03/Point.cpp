/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:22:05 by dle-fur           #+#    #+#             */
/*   Updated: 2025/07/11 10:16:55 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){
}

Point::Point(const float x, const float y) : _x(x), _y(y){
}

Point::Point(Point const& src) : _x(src._x), _y(src._y){
}

Point&	Point::operator=(Point const& other){
	if (this != &other){
		this->~Point();//detruit
		new(this)Point(other);//on reconsruit, car des const ne peuvent pas etre copier
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
