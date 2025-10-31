/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:16:41 by david             #+#    #+#             */
/*   Updated: 2025/10/31 09:59:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	print(int i){
	std::cout << i << " ";
}

void	testList(){
	try{
		int	array[] = {1, 2, 3};
		std::list<int>	list(array, array + 3);

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
	try{
		int	array[] = {10, 20, 30};
		std::vector<int>	vect(array, array + 3);

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
	try{
		int	array[] = {1, 2, 3};
		std::list<int>	list(array, array + 3);

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

	std::cout << "Test List : " << std::endl;
	testList();

	std::cout << "Test Vector : " << std::endl;
	testVector();

	std::cout << "Test Erreur : " << std::endl;
	testError();

	return 0;
}
