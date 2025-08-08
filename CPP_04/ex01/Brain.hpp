/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:24:33 by david             #+#    #+#             */
/*   Updated: 2025/08/08 13:57:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>

class	Brain
{
	public:
		Brain();
		Brain(Brain const& src);
		Brain&	operator=(Brain const& other);
		~Brain();

		void			setIdea(int index, std::string idea);
		std::string		getIdea(int index);

	private:
		std::string	_ideas[100];
};

#endif
