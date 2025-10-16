/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:16:04 by david             #+#    #+#             */
/*   Updated: 2025/10/16 17:27:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	std::cout << "Test tableau vide : " << std::endl;
	Array<int>	arrayEmpty;
	std::cout << "Taille du tableau = " << arrayEmpty.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Test copie tableau : " << std::endl;
	Array<int>	array_a(3);
	array_a[0] = 1;
	array_a[1] = 2;
	array_a[2] = 3;

	std::cout << "Taille du tableau a : " << array_a.size() << std::endl;
	std::cout << "Contenu tableau a : ";
	for (unsigned int i = 0; i < array_a.size(); i++)
	{
		std::cout << array_a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Array<int>	array_b = array_a;
	std::cout << "Taille du tableau b : " << array_b.size() << std::endl;
	std::cout << "Contenu tableau a : ";
	for (unsigned int i = 0; i < array_b.size(); i++)
	{
		std::cout << array_b[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Array<int>	array_c = array_a;
	array_c[0] = 10;
	array_c[1] = 20;
	array_c[2] = 30;
	
	std::cout << "Taille tableau c : " << array_c.size() << std::endl;
	std::cout << "array_a[0] = " << array_a[0] << ", array_c[0] = " << array_c[0] << std::endl;
	std::cout << "array_a[1] = " << array_a[1] << ", array_c[1] = " << array_c[1] << std::endl;
	std::cout << "array_a[2] = " << array_a[2] << ", array_c[2] = " << array_c[2] << std::endl;

	std::cout << std::endl;

	std::cout << "Test exception : " << std::endl;
	try{
		std::cout << array_a[10] << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	return 0;
}
