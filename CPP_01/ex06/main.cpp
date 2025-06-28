/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:22:37 by david             #+#    #+#             */
/*   Updated: 2025/06/28 17:43:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv){
	Harl	Harl;

	if (argc != 2){
		std::cout << "Error: use './harlFilter <level>'" << std::endl;
		return 1;
	}
	system("clear");
	Harl.complain(argv[1]);
	return 0;
}
