/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:54:28 by david             #+#    #+#             */
/*   Updated: 2025/07/03 15:53:42 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

class	Fixed{
	public:
		Fixed();
		Fixed(Fixed const& src);
		~Fixed();

		Fixed&	operator=(Fixed const& rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int	_value;
		static const int	bits = 8;
};

#endif
