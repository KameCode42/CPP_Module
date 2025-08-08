/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:29:12 by david             #+#    #+#             */
/*   Updated: 2025/08/08 14:00:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++){
		_ideas[i] = "";
	}
	std::cout << "Brain est consruit" << std::endl;
}

Brain::Brain(Brain const& src){
	for(int i = 0; i < 100; i++){
		_ideas[i] = src._ideas[i];
	}
}

Brain&	Brain::operator=(Brain const& other){
	if (this != &other){
		for(int i = 0; i < 100; i++){
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain est detruit" << std::endl;
}

void	Brain::setIdea(int index, std::string idea){
	if (index >= 0 && index < 100){
		_ideas[index] = idea;
	}
}

std::string	Brain::getIdea(int index){
	if (index >= 0 && index < 100){
		return _ideas[index];
	}
	return "";
}
