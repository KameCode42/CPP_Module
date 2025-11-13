/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:16:04 by david             #+#    #+#             */
/*   Updated: 2025/11/13 15:10:44 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	testInt(){
	std::cout << "------TEST INT------" << std::endl;
	std::cout << "Test tableau vide : " << std::endl;
	Array<int>	arrayEmpty;
	std::cout << "Taille du tableau = " << arrayEmpty.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Tableau original a : " << std::endl;
	Array<int>	array_a(3);
	array_a[0] = 1;
	array_a[1] = 2;
	array_a[2] = 3;

	std::cout << "Taille du tableau original a : " << array_a.size() << std::endl;
	std::cout << "Contenu du tableau original a : ";
	for (unsigned int i = 0; i < array_a.size(); i++)
	{
		std::cout << array_a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Array<int>	array_b = array_a;
	std::cout << "Copie du tableau a sans modification de valeur : " << std::endl;
	std::cout << "Taille du tableau b : " << array_b.size() << std::endl;
	std::cout << "Contenu du tableau b : ";
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

	std::cout << "Copie du tableau a avec modification de valeur : " << std::endl;
	std::cout << "Taille du tableau c : " << array_c.size() << std::endl;
	std::cout << "Contenu du tableau c : ";
	for (unsigned int i = 0; i < array_c.size(); i++)
	{
		std::cout << array_c[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Contenu du tableau original a : ";
	for (unsigned int i = 0; i < array_a.size(); i++)
	{
		std::cout << array_a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test exception : " << std::endl;
	try{
		std::cout << array_a[10] << std::endl;
	}
	catch(std::exception& e){
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testString(){
	std::cout << "------TEST STRING------" << std::endl;
	std::cout << "Test tableau vide : " << std::endl;
	Array<std::string>	arrayEmpty;
	std::cout << "Taille du tableau = " << arrayEmpty.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Tableau original a : " << std::endl;
	Array<std::string>	array_a(3);
	array_a[0] = "pierre,";
	array_a[1] = "feuille,";
	array_a[2] = "ciseaux";

	std::cout << "Taille du tableau original a : " << array_a.size() << std::endl;
	std::cout << "Contenu du tableau original a : ";
	for (unsigned int i = 0; i < array_a.size(); i++)
	{
		std::cout << array_a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Array<std::string>	array_b = array_a;
	std::cout << "Copie du tableau a sans modification de valeur : " << std::endl;
	std::cout << "Taille du tableau b : " << array_b.size() << std::endl;
	std::cout << "Contenu du tableau b : ";
	for (unsigned int i = 0; i < array_b.size(); i++)
	{
		std::cout << array_b[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Array<std::string>	array_c = array_a;
	array_c[0] = "salut,";
	array_c[1] = "hello,";
	array_c[2] = "bonjour";

	std::cout << "Copie du tableau a avec modification de valeur : " << std::endl;
	std::cout << "Taille du tableau c : " << array_c.size() << std::endl;
	std::cout << "Contenu du tableau c : ";
	for (unsigned int i = 0; i < array_c.size(); i++)
	{
		std::cout << array_c[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Contenu du tableau original a : ";
	for (unsigned int i = 0; i < array_a.size(); i++)
	{
		std::cout << array_a[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test exception : " << std::endl;
	try{
		std::cout << array_a[10] << std::endl;
	}
	catch(std::exception& e){
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(){
	system("clear");

	testInt();
	testString();
	return 0;
}
