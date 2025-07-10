/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:49:55 by david             #+#    #+#             */
/*   Updated: 2025/07/10 13:09:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>
#include <cstdlib>

class	Weapon
{
	public:
		Weapon();
		Weapon(const std::string& type);
		~Weapon();
	
		const std::string&	getType()const;
		void	setType(const std::string& type);

	private:
		std::string _type;
};

#endif