/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:45:12 by david             #+#    #+#             */
/*   Updated: 2025/10/31 10:07:13 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	testSubject(){
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	return;
}

void	testComplete(){
	try{
		Span sp = Span(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::vector<int>	more = {100, 200, 300, 400, 500};
		sp.addNumber(more.begin(), more.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return;
}

void	testBig(){
	try{
		Span sp = Span(10000);

		std::vector<int> array;

		for (size_t i = 0; i < 10000; i++){
			array.push_back(std::rand() % 10000);
		}
		sp.addNumber(array.begin(), array.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return;
}

void	testFull(){
	try{
		Span sp = Span(3);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(20);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return;
}

void	testErrorStorage(){
	try{
		Span sp = Span(1);

		sp.addNumber(6);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return;
}

int	main(){
	system("clear");

	std::cout << "Test Sujet : " << std::endl;
	testSubject();

	std::cout << "Test complet : " << std::endl;
	testComplete();

	std::cout << "Test 10000 : " << std::endl;
	testBig();

	std::cout << "Test Span plein : " << std::endl;
	testFull();

	std::cout << "Test Erreur Stockage : " << std::endl;
	testErrorStorage();

	return 0;
}
