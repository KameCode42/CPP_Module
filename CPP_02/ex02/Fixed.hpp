/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:31:31 by david             #+#    #+#             */
/*   Updated: 2025/07/05 16:44:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& src);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		Fixed&	operator=(Fixed const& src);
		Fixed	operator+(Fixed const& src)const;
		Fixed	operator-(Fixed const& src)const;
		Fixed	operator*(Fixed const& src)const;
		Fixed	operator/(Fixed const& src)const;

		//pre incremente, +1 a la valeur, return l adress avce *this
		Fixed&	operator++();
		//post incremente, return ancienne valeur et ensuite la valeur modifier
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		bool	operator>(Fixed const& src)const;
		bool	operator<(Fixed const& src)const;
		bool	operator>=(Fixed const& src)const;
		bool	operator<=(Fixed const& src)const;
		bool	operator==(Fixed const& src)const;
		bool	operator!=(Fixed const& src)const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void)const;
		float	toFloat(void)const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
	
	private:
		int	_value;
		static const int	bits = 8;
};

std::ostream&	operator<<(std::ostream& os, Fixed const& other);

#endif
