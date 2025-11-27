/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:50:06 by david             #+#    #+#             */
/*   Updated: 2025/11/27 15:42:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <stack>
#include <algorithm>

class	RPN
{
	public:
		RPN();
		RPN(RPN const& src);
		RPN&	operator=(RPN const& other);
		~RPN();

		int	evaluate(std::string const& expression);

		class	ErrorExpression : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif
