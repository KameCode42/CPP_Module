/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:26:38 by david             #+#    #+#             */
/*   Updated: 2025/07/03 18:09:30 by david            ###   ########.fr       */
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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(Fixed const& rhs);
		int		toInt(void)const;
		float	toFloat(void)const;
	
	private:
		int	_value;
		static const int	bits = 8;
};

std::ostream&	operator<<(std::ostream& other, Fixed const& rhs);

#endif
