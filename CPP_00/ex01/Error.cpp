/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:39:33 by david             #+#    #+#             */
/*   Updated: 2025/07/03 18:27:05 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

bool	isNotEmpty(const std::string& s){
	if (s.empty())
	{
		std::cout << "Error : the string must not be empty" << std::endl;
		return false;
	}
	return true;
}

bool	isWhiteSpace(const std::string& s){
	for (size_t i = 0; i < s.length(); ++i){
		if (!std::isspace(static_cast<unsigned char>(s[i]))){
			return true;
		}
	}
	std::cout << "Error: no spaces or tabs only" << std::endl;
	return false;
}

bool	isAllAlpha(const std::string& s){
	for (size_t i = 0; i < s.length(); i++)
	{
		unsigned char c = static_cast<unsigned char>(s[i]);
		if (!std::isalpha(c) && !std::isspace(c)){
			std::cout << "Error : only letters" << std::endl;
			return false;
		}
	}
	return true;
}

bool	isAllDigit(const std::string& s){
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i]))){
			std::cout << "Error : only numeric numbers" << std::endl;
			return false;
		}
	}
	return true;
}

bool	validIndex(const std::string& idx)
{
	if ((idx.length() != 1) || (idx[0] < '0' || idx[0] > '7')){
		std::cout << "Error : index between 0 and 7 and only one digit" << std::endl;
		return false;
	}
	return true;
}

bool	validText(const std::string& s){
	return isNotEmpty(s)
		&& isWhiteSpace(s)
		&& isAllAlpha(s);
}

bool	validNumber(const std::string& s){
	return isNotEmpty(s)
		&& isWhiteSpace(s)
		&& isAllDigit(s);
}
