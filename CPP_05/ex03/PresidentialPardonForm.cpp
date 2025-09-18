/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:30:25 by david             #+#    #+#             */
/*   Updated: 2025/09/18 11:41:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src){
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& other){
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Le formulaire " << this->_target << " est detruit" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm const& presidential){
	std::cout << "Nom formulaire : " << presidential.getName() << std::endl;
	std::cout << "Grade requis pour signer : " << presidential.getGradeToSigned() << std::endl;
	std::cout << "Grade requis pour executer : " << presidential.getGradeToExecute() << std::endl;
	std::cout  << "Est-il signe (0 = non signe, 1 = signe) ? " << presidential.getIsSigned() << std::endl;
	return os;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	std::cout << this->_target << " a ete gracie par Zaphod Beeblebrox" << std::endl;
}
