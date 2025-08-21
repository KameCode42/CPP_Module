/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:16:08 by david             #+#    #+#             */
/*   Updated: 2025/08/21 14:35:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(){
	system("clear");
	std::cout << "Construction : " << std::endl;
	const Animal*		meta = new Animal();
	const Animal*		j = new Dog();
	const Animal*		i = new Cat();
	const WrongAnimal*	l = new WrongAnimal();
	const WrongAnimal*	k = new WrongCat();
	std::cout << std::endl;
	std::cout << "Type d'animaux : " << std::endl;
	std::cout << "Type Dog : " << j->getType() << std::endl;
	std::cout << "Type Cat : " << i->getType() << std::endl;
	std::cout << "Type WrongCat : " << k->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Son des animaux (avec polymorphism) : " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "Son des animaux (sans polymorphism) : " << std::endl;
	l->makeSound();
	k->makeSound();
	std::cout << std::endl;
	std::cout << "Destruction : " << std::endl;
	delete meta;
	delete j;
	delete i;
	delete k;
	return 0;
}
