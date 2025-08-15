/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:16:08 by david             #+#    #+#             */
/*   Updated: 2025/08/15 10:18:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(){
	system("clear");
	//test class abstraite
	//Animal	animal;
	std::cout << "-----CREATE DOG-----" << std::endl;
	const Animal* j = new Dog();
	std::cout << "-----CREATE CAT-----" << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << "-----DESTROY DOG-----" << std::endl;
	delete j;
	std::cout << "-----DESTROY CAT-----" << std::endl;
	delete i;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-----TAB ANIMAUX-----" << std::endl;
	Animal*	tab[6];
	std::cout << "-----CREATION TAB----" << std::endl;
	for(int i = 0; i < 6; i++){
		std::cout << "construction animal : " << i << std::endl;
		if (i < 3)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}
	std::cout << std::endl;
	std::cout << "-----DESTROY TAB----" << std::endl;
	for(int i = 0; i < 6; i++){
		std::cout << "destruction animal : " << i << std::endl;
		delete tab[i];
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-----USE BRAIN-----" << std::endl;
	Dog	dog1;
	dog1.getBrain()->setIdea(0, "sauter");
	dog1.getBrain()->setIdea(1, "manger");
	Dog	dog2 = dog1;
	dog2.getBrain()->setIdea(0, "dormir");
	dog2.getBrain()->setIdea(1, "boire");
	std::cout << std::endl;
	Cat	cat1;
	cat1.getBrain()->setIdea(0, "grimper");
	cat1.getBrain()->setIdea(1, "courir");
	Cat	cat2 = cat1;
	cat2.getBrain()->setIdea(0, "s'allonger");
	cat2.getBrain()->setIdea(1, "s'etirer");
	std::cout << std::endl;
	std::cout << "Cerveau dog1" << std::endl;
	std::cout << "dog 1 idee[0] : " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog 1 idee[1] : " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
	std::cout << "Cerveau dog2" << std::endl;
	std::cout << "dog 2 idee[0] : " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog 2 idee[1] : " << dog2.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Cerveau cat1" << std::endl;
	std::cout << "cat 1 idee[0] : " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat 1 idee[1] : " << cat1.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
	std::cout << "Cerveau cat2" << std::endl;
	std::cout << "cat 2 idee[0] : " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat 2 idee[1] : " << cat2.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-----Destruction-----"<< std::endl;
	return 0;
}
