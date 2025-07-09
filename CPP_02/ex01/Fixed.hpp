/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:26:38 by david             #+#    #+#             */
/*   Updated: 2025/07/09 17:45:37 by dle-fur          ###   ########.fr       */
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
		Fixed&	operator=(Fixed const& other);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void)const;
		float	toFloat(void)const;
	
	private:
		int	_value;
		static const int	bits = 8;
};

std::ostream&	operator<<(std::ostream& os, Fixed const& fixed);

#endif
