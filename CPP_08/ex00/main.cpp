/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:16:41 by david             #+#    #+#             */
/*   Updated: 2025/10/17 14:36:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	print(int i){
	std::cout << i << " ";
}

void	testList(){
	std::cout << "Test List : " << std::endl;
	try{
		std::list<int>	list;

		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		
		std::cout << "Contenu de la list : ";
		for_each(list.cbegin(), list.cend(), print);
		std::cout << std::endl;

		std::cout << "Occurence a trouvee : 3" << std::endl;
		easyfind(list, 3);
	}
	catch(std::exception& e){
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testVector(){
	std::cout << "Test Vector : " << std::endl;
	try{
		std::vector<int>	vect;

		vect.push_back(10);
		vect.push_back(20);
		vect.push_back(30);
		
		std::cout << "Contenu du tableau : ";
		for_each(vect.cbegin(), vect.cend(), print);
		std::cout << std::endl;

		std::cout << "Occurence a trouvee : 20" << std::endl;
		easyfind(vect, 20);
	}
	catch(std::exception& e){
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testError(){
	std::cout << "Test Erreur : " << std::endl;
	try{
		std::list<int>	list;

		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		
		std::cout << "Contenu de la list : ";
		for_each(list.cbegin(), list.cend(), print);
		std::cout << std::endl;

		std::cout << "Occurence a trouvee : 4" << std::endl;
		easyfind(list, 4);
	}
	catch(std::exception& e){
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(){
	system("clear");

	testList();
	testVector();
	testError();

	return 0;
}
