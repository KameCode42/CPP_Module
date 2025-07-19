/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:34:32 by david             #+#    #+#             */
/*   Updated: 2025/07/19 14:14:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(){
	system("clear");
	ClapTrap	ClapTrap("Robot 2B");
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.takeDamage(5);
	std::cout << std::endl;
	ClapTrap.takeDamage(5);
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.beRepaired(2);
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
}
