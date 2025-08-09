/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:11:45 by david             #+#    #+#             */
/*   Updated: 2025/08/09 14:03:10 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>
#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const& src);
		WrongAnimal&	operator=(WrongAnimal const& other);
		~WrongAnimal();

		void			makeSound()const;
		std::string		getType()const;

	protected:
		std::string	_type;
};

#endif
