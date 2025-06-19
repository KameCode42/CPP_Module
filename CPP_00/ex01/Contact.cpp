/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:09 by david             #+#    #+#             */
/*   Updated: 2025/06/19 13:08:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}
Contact::~Contact(){
}
void	Contact::setFirstName(const std::string& firstName){
	this->_firstName = firstName;
}
void	Contact::setLastName(const std::string& lastName){
	this->_lastName = lastName;
}
void	Contact::setNickName(const std::string& nickName){
	this->_nickName = nickName;
}
void	Contact::setPhoneNumber(const std::string& phoneNumber){
	this->_phoneNumber = phoneNumber;
}
void	Contact::setDarkSecret(const std::string& darkSecret){
	this->_darkSecret = darkSecret;
}
const std::string&	Contact::getFirstName()const{
	return this->_firstName;
}
const std::string&	Contact::getLastName()const{
	return this->_lastName;
}
const std::string&	Contact::getNickName()const{
	return this->_nickName;
}
const std::string&	Contact::getPhoneNumber()const{
	return this->_phoneNumber;
}
const std::string&	Contact::getDarkSecret()const{
	return this->_darkSecret;
}
