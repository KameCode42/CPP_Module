/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:11:55 by david             #+#    #+#             */
/*   Updated: 2025/10/11 16:35:42 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	printTab(T const& content){
	std::cout << content << " ";
}

template<typename T>
void	multiplication(T& content){
	content *= 2;
	std::cout << content << " ";
}

template<typename T>
void	toUpper(T& content){
	for (size_t i = 0; i < content.length(); i++)
	{
		if (content[i] >= 'a' && content[i] <= 'z')
			content[i] = content[i] - 32;
	}
	std::cout << content << " ";
}

int	main()
{
	system("clear");
	std::cout << "Affichage non const : " << std::endl;

	/*int*/
	int	arrayInt[] = {1, 2, 3, 4, 5};
	int	lengthInt = 5;

	std::cout << "Original int : ";
	iter(arrayInt, lengthInt, printTab<int>);
	std::cout << std::endl;
	std::cout << "Iter int : ";
	iter(arrayInt, lengthInt, multiplication<int>);
	std::cout << std::endl;
	std::cout << std::endl;

	/*string*/
	std::string	arrayStr[] = {"pierre,", "feuille,", "ciseaux"};
	int	lengthStr = 3;

	std::cout << "Original string : ";
	iter(arrayStr, lengthStr, printTab<std::string>);
	std::cout << std::endl;
	std::cout << "Iter string : ";
	iter(arrayStr, lengthStr, toUpper<std::string>);
	
	std::cout << std::endl;
	std::cout << std::endl;
	/*-----------------------------------------------------------*/

	std::cout << "Affichage const : " << std::endl;

	/*int*/
	const int	arrayConstInt[] = {1, 2, 3, 4, 5};
	int			lengthConstInt = 5;

	iter(arrayConstInt, lengthConstInt, printTab<int>);
	std::cout << std::endl;
	//decocher pour erreur const
	//iter(arrayConstInt, lengthConstInt, multiplication<int>);

	/*string*/
	const std::string	arrayConstStr[] = {"pierre,", "feuille,", "ciseaux"};
	int	lengthConstStr = 3;

	iter(arrayConstStr, lengthConstStr, printTab<std::string>);
	std::cout << std::endl;
	return 0;
}
