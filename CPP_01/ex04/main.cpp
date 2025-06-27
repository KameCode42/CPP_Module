/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:20:21 by david             #+#    #+#             */
/*   Updated: 2025/06/27 12:04:12 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int	main(int argc, char **argv)
{
	std::string		s1;
	std::string		s2;

	if (argc != 4){
		std::cout << "Error: not enough or too much argument" << std::endl;
		return 1;
	}
	std::ifstream	ifs(argv[1]);//ouverture via constrcuteur donc pas besoin de open
	s1 = argv[2];// chaine a rechercher
	s2 = argv[3];//chaine a remplacer
	if (s1.empty()){
		std::cout << "Error: string s1 cannot be empty" << std::endl;
		return 1;
	}
	if (!ifs){//controler ouverture
		std::cout << "Error: unable to open file" << std::endl;
		return 1;
	}
	std::string		outName = argv[1];
	outName.append(".replace");
	std::ofstream	ofs(outName.c_str());
	if (!ofs){
		std::cout << "Error: unable to create file" << outName << std::endl;
		return 1;
	}
	std::string	line;//lire le fichier ligne par ligne
	while(std::getline(ifs, line))//parcours le fichier
	{
		std::string	result;//on va copier dans result
		size_t	start = 0;//position de depart de la recherche
		size_t	pos = line.find(s1, start);//pos recoit le resultat par ex pos = 5 qui est 'c' de clean
		while(pos != std::string::npos)//tant qu il y a des occurence
		{
			result += line.substr(start, pos - start);
			result += s2;
			start = pos + s1.length();
			pos = line.find(s1, start);
		}
		result += line.substr(start);
		ofs << result << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
