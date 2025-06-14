/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:33 by david             #+#    #+#             */
/*   Updated: 2025/06/14 09:27:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
init list -> on init a la construction les variable
*/
PhoneBook::PhoneBook() : _nextIndex(0), _count(0){
}
PhoneBook::~PhoneBook(){
}

void	PhoneBook::add_contact(){
	//declarer les variable
	//commencer le questionnaire
	//utiliser std::getline et std::cin
}