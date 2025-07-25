/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:55:33 by david             #+#    #+#             */
/*   Updated: 2025/07/24 16:06:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const& src);
		Cat&	operator=(Cat const& other);
		virtual ~Cat();

		virtual void	makeSound()const;
		std::string		getType()const;
};

#endif
