/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:38:16 by david             #+#    #+#             */
/*   Updated: 2025/06/16 10:28:15 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contact.hpp"

bool	isNotEmpty(const std::string& s);
bool	isWhiteSpace(const std::string& s);
bool	isAllDigit(const std::string& s);
bool	isAllAlpha(const std::string& s);
bool	validText(const std::string& s);
bool	validNumber(const std::string& s);
bool	validIndex(const std::string& idx);

#endif