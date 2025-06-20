/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:01:35 by david             #+#    #+#             */
/*   Updated: 2025/06/20 11:33:07 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);

	private:
		std::string	_name;
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
