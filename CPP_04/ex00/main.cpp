/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:16:08 by david             #+#    #+#             */
/*   Updated: 2025/07/25 09:12:11 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(){
	system("clear");
	std::cout << "-----AVEC POLYMORPHISM-----" << std::endl;
	std::cout << std::endl;
	std::cout << "-----CONSTRUCTEUR-----" << std::endl;
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	std::cout << "-----HERITAGE DOG-----" << std::endl;
	const Animal	*j = new Dog();
	std::cout << std::endl;
	std::cout << "-----HERITAGE CAT-----" << std::endl;
	const Animal	*i = new Cat();

	std::cout << std::endl;
	std::cout << "-----TYPE D'ANIMAUX-----" << std::endl;
	std::cout << "Type Dog : " <<j->getType() << std::endl;
	std::cout << "Type Cat : " <<i->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "-----SON DES ANIMAUX-----" << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	std::cout << std::endl;
	std::cout << "-----DESTRUCTEUR-----" << std::endl;
	delete	meta;
	delete	j;
	delete	i;

	std::cout << std::endl;
	std::cout << "=================================" << std::endl;
	std::cout << std::endl;

	std::cout << "-----SANS POLYMORPHISM-----" << std::endl;
	std::cout << std::endl;
	std::cout << "-----CONSTRUCTEUR-----" << std::endl;
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	std::cout << std::endl;
	std::cout << "-----HERITAGE WRONG CAT-----" << std::endl;
	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "-----TYPE D'ANIMAUX-----" << std::endl;
	std::cout << "Type Wrong Cat : " << wrongCat->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "-----SON DES ANIMAUX-----" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;
	std::cout << "-----DESTRUCTEUR-----" << std::endl;
	delete wrongAnimal;
	delete wrongCat;
	return 0;
}
