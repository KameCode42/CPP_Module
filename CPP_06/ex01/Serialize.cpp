/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:34:09 by david             #+#    #+#             */
/*   Updated: 2025/10/09 14:25:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t	Serialize::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serialize::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
