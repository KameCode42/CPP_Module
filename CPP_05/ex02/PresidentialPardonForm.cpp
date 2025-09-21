/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:30:25 by david             #+#    #+#             */
/*   Updated: 2025/09/21 10:26:32 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*-------------------------------constructeur--------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm(target, 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src){
}

/*-------------------------------operateur-------------------------------------*/

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm const& presidential){
	std::cout << "Nom formulaire : " << presidential.getName() << std::endl;
	std::cout << "Grade requis pour signer : " << presidential.getGradeToSigned() << std::endl;
	std::cout << "Grade requis pour executer : " << presidential.getGradeToExecute() << std::endl;
	std::cout  << "Est-il signe (0 = non signe, 1 = signe) ? " << presidential.getIsSigned() << std::endl;
	return os;
}

/*-------------------------------destructeur-----------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Le formulaire " << this->_target << " est detruit" << std::endl;
}

/*-------------------------------ft_membre-------------------------------------*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	std::cout << this->_target << " a ete gracie par Zaphod Beeblebrox" << std::endl;
}
