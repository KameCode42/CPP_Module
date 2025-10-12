/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:11:55 by david             #+#    #+#             */
/*   Updated: 2025/10/12 10:25:04 by david            ###   ########.fr       */
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
void	toUpperString(T& content){
	for (size_t i = 0; i < content.length(); i++){
		if (content[i] >= 'a' && content[i] <= 'z')
			content[i] = content[i] - 32;
	}
	std::cout << content << " ";
}

template<typename T>
void	toLowerChar(T& content){
	if (content >= 'A' && content <= 'Z')
		content = content + 32;
	std::cout << content << " ";
}

int	main()
{
	system("clear");
	std::cout << "Affichage non const : " << std::endl;
	std::cout << "---------------------" << std::endl;

	int			arrayInt[] = {1, 2, 3, 4, 5};
	char		arrayChar[] = {'A', 'B', 'C'};
	double		arrayDouble[] = {1.1, 2.2, 3.3, 4.4};
	std::string	arrayString[] = {"pierre,", "feuille"};

	int	lengthInt = 5;
	int	lengthChar = 3;
	int	lengthDouble = 4;
	int	lengthString = 2;

	/*Int*/
	std::cout << "Original int : ";
	iter(arrayInt, lengthInt, printTab<int>);
	std::cout << std::endl;
	std::cout << "Iter int : ";
	iter(arrayInt, lengthInt, multiplication<int>);
	std::cout << std::endl;

	std::cout << std::endl;

	/*Double*/
	std::cout << "Original double : ";
	iter(arrayDouble, lengthDouble, printTab<double>);
	std::cout << std::endl;
	std::cout << "Iter double : ";
	iter(arrayDouble, lengthDouble, multiplication<double>);
	std::cout << std::endl;

	std::cout << std::endl;

	/*Char*/
	std::cout << "Original char : ";
	iter(arrayChar, lengthChar, printTab<char>);
	std::cout << std::endl;
	std::cout << "Iter char : ";
	iter(arrayChar, lengthChar, toLowerChar<char>);
	std::cout << std::endl;

	std::cout << std::endl;

	/*String*/
	std::cout << "Original string : ";
	iter(arrayString, lengthString, printTab<std::string>);
	std::cout << std::endl;
	std::cout << "Iter string : ";
	iter(arrayString, lengthString, toUpperString<std::string>);
	std::cout << std::endl;
	
	std::cout << std::endl;

	std::cout << "Affichage const : " << std::endl;
	std::cout << "---------------------" << std::endl;
	
	const int			arrayConstInt[] = {1, 2, 3, 4, 5};
	const char			arrayConstChar[] = {'A', 'B', 'C'};
	const double		arrayConstDouble[] = {1.1, 2.2, 3.3, 4.4};
	const std::string	arrayConstString[] = {"pierre,", "feuille"};

	int	lengthConstInt = 5;
	int	lengthConstChar = 3;
	int	lengthConstDouble = 4;
	int	lengthConstString = 2;

	/*Int*/
	std::cout << "Original int : ";
	iter(arrayConstInt, lengthConstInt, printTab<int>);
	std::cout << std::endl;

	/*Double*/
	std::cout << "Original double : ";
	iter(arrayConstDouble, lengthConstDouble, printTab<double>);
	std::cout << std::endl;

	/*Char*/
	std::cout << "Original char : ";
	iter(arrayConstChar, lengthConstChar, printTab<char>);
	std::cout << std::endl;

	/*String*/
	std::cout << "Original string : ";
	iter(arrayConstString, lengthConstString, printTab<std::string>);
	std::cout << std::endl;

	return 0;
}
