/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:47:00 by david             #+#    #+#             */
/*   Updated: 2025/06/21 10:16:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>
#include <cstdlib>

class	Zombie{
	
	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	setName(std::string name);
	
	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
