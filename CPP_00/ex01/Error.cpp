/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:39:33 by david             #+#    #+#             */
/*   Updated: 2025/06/14 16:59:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

bool	isNotEmpty(const std::string& s){
	if (s.empty())
	{
		std::cout << "The string must not be empty" << std::endl;
		return false;
	}
	return true;
}

bool	isWhiteSpace(const std::string& s){
	for (size_t i = 0; i < s.length(); i++)
	{
		if (std::isspace(static_cast<unsigned char>(s[i])))
		{
			std::cout << "No spaces or tabs" << std::endl;
			return false;
		}
	}
	return true;
}

bool	isAllAlpha(const std::string& s){
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isalpha(static_cast<unsigned char>(s[i])))
		{
			std::cout << "Must contain only letters" << std::endl;
			return false;
		}
	}
	return true;
}

bool	isAllDigit(const std::string& s){
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
		{
			std::cout << "Must contain only numeric numbers" << std::endl;
			return false;
		}
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

//dans les std::....
//valeur de retour 1 si c est juste et 0 si y a une erreur
//! == 0
