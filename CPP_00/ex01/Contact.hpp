/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:47:56 by david             #+#    #+#             */
/*   Updated: 2025/06/14 14:33:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class	Contact
{
	public:
		Contact();
		~Contact();
		
		void	setFirstName(const std::string& firstName);
		void	setLastName(const std::string& lastName);
		void	setNickName(const std::string& nickName);
		void	setPhoneNumber(const std::string& phoneNumber);
		void	setDarkSecret(const std::string& darkSecret);
		const std::string&	getFirstName()const;
		const std::string&	getLastName()const;
		const std::string&	getNickName()const;
		const std::string&	getPhoneNumber()const;
		const std::string&	getDarkSecret()const;
		
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkSecret;
};

#endif
