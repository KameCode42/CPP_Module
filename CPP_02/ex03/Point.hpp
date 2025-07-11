/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:18:40 by dle-fur           #+#    #+#             */
/*   Updated: 2025/07/11 09:52:28 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(Point const& src);
		Point&	operator=(Point const& other);
		~Point();

		Fixed const	getX()const;
		Fixed const	getY()const;
		
	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream&	operator<<(std::ostream& os, Point const& point);

#endif
