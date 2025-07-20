/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:34:32 by david             #+#    #+#             */
/*   Updated: 2025/07/20 18:00:41 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	system("clear");
	std::cout << "-------OBJET CLAPTRAP-------------" << std::endl;
	ClapTrap	ClapTrap("Robot 2B");
	std::cout << std::endl;
	std::cout << "-------HERITAGE SCAVTRAP----------" << std::endl;
	ScavTrap	ScavTrap("Robot 9S");
	std::cout << std::endl;
	std::cout << "-------HERITAGE FRAGTRAP----------" << std::endl;
	FragTrap	FragTrap("Robot A2");
	std::cout << std::endl;
	std::cout << "-------HERITAGE DIAMONDTRAP-------" << std::endl;
	DiamondTrap	Diamond("Vecna");
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
	Diamond.attack("Robot 2B");
	std::cout << std::endl;
	ClapTrap.takeDamage(30);
	std::cout << std::endl;
	Diamond.whoAmI();
	std::cout << std::endl;
	return 0;
}
