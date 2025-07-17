/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:34:32 by david             #+#    #+#             */
/*   Updated: 2025/07/17 19:30:48 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	test(){
	ClapTrap	ClapTrap("Robot 2B");

	ClapTrap.setEnergyPoints(0);
	ClapTrap.setAttackDamage(2);
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
}

int	main(){
	system("clear");
	ClapTrap	ClapTrap("Robot 2B");

	ClapTrap.setAttackDamage(5);
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ClapTrap.takeDamage(5);
	std::cout << std::endl;
	ClapTrap.beRepaired(2);
	std::cout << std::endl;
	ClapTrap.takeDamage(7);
	std::cout << std::endl;
	ClapTrap.setAttackDamage(2);
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	std::cout << "-----TEST ERROR-----" << std::endl;
	test();
	return (0);
}
