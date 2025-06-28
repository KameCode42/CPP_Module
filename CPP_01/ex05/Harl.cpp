/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:03:12 by david             #+#    #+#             */
/*   Updated: 2025/06/28 16:30:12 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void	Harl::debug(void){
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void){
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void){
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level){
	std::string	arrayLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*arrayPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for(int i = 0; i < 4; i++){
		if (arrayLevel[i] == level){
			(this->*arrayPtr[i])();
			return;
		}
	}
	std::cout << "level " << level << " : unknown" << std::endl;
}
