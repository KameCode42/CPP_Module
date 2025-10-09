/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:34:00 by david             #+#    #+#             */
/*   Updated: 2025/10/09 13:17:18 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class	Serialize
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serialize();
		Serialize(Serialize const& src);
		Serialize&	operator=(Serialize const& other);
		~Serialize();
};

#endif
