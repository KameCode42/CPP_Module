/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:58:19 by david             #+#    #+#             */
/*   Updated: 2025/06/28 16:19:24 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(){
	Harl	Harl;

	system("clear");
	std::cout << "----------VALID TEST----------" << std::endl;
	Harl.complain("DEBUG");
	Harl.complain("INFO");
	Harl.complain("WARNING");
	Harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "----------INVALID TEST--------" << std::endl;
	Harl.complain("MESSAGE");
	Harl.complain("SNAKE");
	Harl.complain("");
	return 0;
}
