/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:10 by david             #+#    #+#             */
/*   Updated: 2025/07/24 16:02:45 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const& src);
		Dog&	operator=(Dog const& other);
		virtual ~Dog();

		virtual void	makeSound()const;
		std::string		getType()const;
};

#endif
