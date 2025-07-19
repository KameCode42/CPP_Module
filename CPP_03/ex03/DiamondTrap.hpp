/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:15:17 by david             #+#    #+#             */
/*   Updated: 2025/07/19 11:40:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string _name);
		DiamondTrap(DiamondTrap const& src);
		DiamondTrap&	operator=(DiamondTrap const& other);
		~DiamondTrap();

		void	whoAmI();
		void	attack(const std::string& target);

	private:
		std::string	_name;
};

#endif
