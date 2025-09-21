/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:00:15 by david             #+#    #+#             */
/*   Updated: 2025/09/21 10:29:06 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*-------------------------------constructeur--------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm(target, 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src){
}

/*-------------------------------operateur-------------------------------------*/

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, ShrubberyCreationForm const& schrubbery){
	std::cout << "Nom formulaire : " << schrubbery.getName() << std::endl;
	std::cout << "Grade requis pour signer : " << schrubbery.getGradeToSigned() << std::endl;
	std::cout << "Grade requis pour executer : " << schrubbery.getGradeToExecute() << std::endl;
	std::cout  << "Est-il signe (0 = non signe, 1 = signe) ? " << schrubbery.getIsSigned() << std::endl;
	return os;
}

/*-------------------------------destructeur-----------------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Le formulaire " << this->_target << " est detruit" << std::endl;
}

/*-------------------------------ft_membre-------------------------------------*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::ofstream	ofs(_target + "_shrubbery");
	if (!ofs)
	{
		std::cout << "Erreur : impossible de creer " << _target << std::endl;
		return;
	}
	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\ //  ~" << std::endl;
	ofs << "_- -   | | _- _" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "      // \\\\" << std::endl;
	ofs.close();
}
