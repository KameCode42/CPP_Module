/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:12:09 by david             #+#    #+#             */
/*   Updated: 2025/09/18 11:29:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src){
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Le formulaire " << this->_target << " est detruit" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm const& roboto){
	std::cout << "Nom formulaire : " << roboto.getName() << std::endl;
	std::cout << "Grade requis pour signer : " << roboto.getGradeToSigned() << std::endl;
	std::cout << "Grade requis pour executer : " << roboto.getGradeToExecute() << std::endl;
	std::cout  << "Est-il signe (0 = non signe, 1 = signe) ? " << roboto.getIsSigned() << std::endl;
	return os;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	random = rand() % 2;

	if (random == 1)
		std::cout << "BZZZZZZZ " << this->_target << " a ete robotomiser avec succès" << std::endl;
	else
		std::cout << "La robotomisation de " << this->_target << " a echoue" << std::endl;
}
