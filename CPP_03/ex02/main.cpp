/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:34:32 by david             #+#    #+#             */
/*   Updated: 2025/07/19 15:11:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(){
	system("clear");
	std::cout << "-------OBJET CLAPTRAP-------------" << std::endl;
	ClapTrap	ClapTrap("Robot 2B");
	std::cout << std::endl;
	std::cout << "-------COPY & INIT SCAVTRAP-------" << std::endl;
	ScavTrap	ScavTrap("Robot 9S");
	std::cout << std::endl;
	std::cout << "-------COPY & INIT FRAGTRAP-------" << std::endl;
	FragTrap	FragTrap("Robot A2");
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ScavTrap.takeDamage(0);
	std::cout << std::endl;
	ScavTrap.beRepaired(0);
	std::cout << std::endl;
	ScavTrap.guardGate();
	std::cout << std::endl;
	ScavTrap.attack("Robot 2B");
	std::cout << std::endl;
	ClapTrap.takeDamage(20);
	std::cout << std::endl;
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	FragTrap.attack("Robot 9S");
	std::cout << std::endl;
	ScavTrap.takeDamage(30);
	std::cout << std::endl;
	FragTrap.highFivesGuys();
	std::cout << std::endl;
	ScavTrap.attack("Robot A2");
	std::cout << std::endl;
	FragTrap.takeDamage(20);
	std::cout << std::endl;
	FragTrap.beRepaired(10);
	std::cout << std::endl;
	return 0;
}
