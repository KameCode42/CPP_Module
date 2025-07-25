/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:46:42 by david             #+#    #+#             */
/*   Updated: 2025/06/27 10:21:23 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	testHordeZombie(int size, std::string name){
	Zombie	*horde = NULL;

	horde = zombieHorde(size, name);
	delete[] horde;
}

int	main(){
	system("clear");
	std::cout << "--------VALID TEST 1------------" << std::endl;
	testHordeZombie(3, "kratos");
	std::cout << std::endl;
	std::cout << "--------VALID TEST 2------------" << std::endl;
	testHordeZombie(10, "aloy");
	std::cout << std::endl;
	std::cout << "--------VALID TEST 3------------" << std::endl;
	testHordeZombie(20, "astro");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "--------ERROR TEST 1------------" << std::endl;
	testHordeZombie(0, "kratos");
	std::cout << std::endl;
	std::cout << "--------ERROR TEST 2------------" << std::endl;
	testHordeZombie(-5, "kratos");
	std::cout << std::endl;
	std::cout << "--------ERROR TEST 3------------" << std::endl;
	testHordeZombie(5, "");
	return 0;
}
