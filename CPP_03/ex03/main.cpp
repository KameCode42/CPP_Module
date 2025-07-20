/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:34:32 by david             #+#    #+#             */
/*   Updated: 2025/07/20 10:56:43 by david            ###   ########.fr       */
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
	std::cout << "-------COPY & INIT SCAVTRAP-------" << std::endl;
	ScavTrap	ScavTrap("Robot 9S");
	std::cout << std::endl;
	std::cout << "-------COPY & INIT FRAGTRAP-------" << std::endl;
	FragTrap	FragTrap("Robot A2");
	std::cout << std::endl;
	std::cout << "-------COPY & INIT DIAMONDTRAP----" << std::endl;
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
