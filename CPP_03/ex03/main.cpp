/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:34:32 by david             #+#    #+#             */
/*   Updated: 2025/07/18 18:24:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(){
	system("clear");
	std::cout << "-----OBJET CLAPTRAP-----" << std::endl;
	ClapTrap	ClapTrap("Robot 2B");
	std::cout << "-----OBJET HERITE SCAV--" << std::endl;
	ScavTrap	ScavTrap("Robot 9S");
	std::cout << std::endl;
	std::cout << "-----OBJET HERITE FRAG--" << std::endl;
	FragTrap	FragTrap("Robot A2");
	std::cout << std::endl;
	std::cout << "-----OBJET HERITE DIAM--" << std::endl;
	DiamondTrap("Robot Vecna");
	std::cout << std::endl;



	
	/*
	std::cout << "-----TEST---------------" << std::endl;
	ClapTrap.setAttackDamage(5);
	ClapTrap.attack("Robot 9S");
	std::cout << std::endl;
	ScavTrap.takeDamage(5);
	std::cout << std::endl;
	ScavTrap.guardGate();
	std::cout << std::endl;
	ScavTrap.beRepaired(3);
	std::cout << std::endl;
	ScavTrap.attack("Robot 2B");
	std::cout << std::endl;
	ClapTrap.takeDamage(20);
	std::cout << std::endl;
	ClapTrap.setAttackDamage(2);
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
	*/
	return (0);
}
