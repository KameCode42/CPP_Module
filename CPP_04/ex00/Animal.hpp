/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:16:50 by david             #+#    #+#             */
/*   Updated: 2025/07/25 14:25:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>
#include <cstdlib>

class	Animal
{
	public:
		Animal();
		Animal(Animal const& src);
		Animal&	operator=(Animal const& other);
		virtual ~Animal();

		virtual void	makeSound()const;
		std::string		getType()const;

	protected:
		std::string	_type;
};

#endif
