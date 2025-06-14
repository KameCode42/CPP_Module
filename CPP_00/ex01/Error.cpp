/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:39:33 by david             #+#    #+#             */
/*   Updated: 2025/06/14 14:52:58 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

bool	isNotEmpty(const std::string& s)
{
	if (s.empty())
	{
		std::cout << "the string must not be empty" << std::endl;
		return false;
	}
	return true;
}

//hasNoWhitespace(s)

//isAlldigit(s);

//sAllLetters(s);

//valdiatetext
//return
// sNotEmpty(s)
// && hasNoWhitespace(s)
        //&& isAllLetters(s);

		
//validatenumber
//return
// sNotEmpty(s)
// && hasNoWhitespace(s)
        //&& isAlldigit(s);
