/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:44:46 by david             #+#    #+#             */
/*   Updated: 2025/06/21 10:28:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

int	main(){
	system("clear");
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "----MEMORY ADDRESS----" << std::endl;
	std::cout << "Memory address of the variable str : "<< &str << std::endl;
	std::cout << "Address of memory content in stringPTR : " << stringPTR << std::endl;
	std::cout << "Address of memory content in stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "--------VALUE---------" << std::endl;
	std::cout << "Value of the string variable : " << str << std::endl;
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF : " << stringREF << std::endl;

	return 0;
}