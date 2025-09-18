/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:32:30 by david             #+#    #+#             */
/*   Updated: 2025/09/18 10:01:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*-------------------------------constructeur--------------------------------*/

AForm::AForm(const std::string name, const int gradeToSigned, const int gradeToExecute) :
_name(name), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute){
	this->_isSigned = false;
	if (this->_gradeToSigned < 1 || this->_gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException(_name);
	}
	else if (this->_gradeToSigned > 150 || this->_gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException(_name);
	}
}

AForm::AForm(AForm const& src) :
_name(src._name), _gradeToSigned(src._gradeToSigned), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned){
}

/*-------------------------------operateur-------------------------------------*/

AForm&	AForm::operator=(AForm const& other){
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, AForm const& Aform){
	std::cout << "Nom formulaire : " << Aform.getName() << std::endl;
	std::cout << "Grade requis pour signer : " << Aform.getGradeToSigned() << std::endl;
	std::cout << "Grade requis pour executer : " << Aform.getGradeToExecute() << std::endl;
	std::cout  << "Est-il signe (0 = non signe, 1 = signe) ? " << Aform.getIsSigned() << std::endl;
	return os;
}

/*-------------------------------destructeur-----------------------------------*/

AForm::~AForm(){
	std::cout << "Le formulaire " << this->_name << " est detruit" << std::endl;
}

/*-------------------------------getter----------------------------------------*/

const std::string	AForm::getName()const{
	return this->_name;
}

bool	AForm::getIsSigned()const{
	return this->_isSigned;
}

const int	AForm::getGradeToSigned()const{
	return this->_gradeToSigned;
}

const int	AForm::getGradeToExecute()const{
	return this->_gradeToExecute;
}

/*-------------------------------ft membre-------------------------------------*/

void	AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSigned){
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " a pu signer " << this->getName() << std::endl;
		std::cout << "Signature du formulaire : " << this->_isSigned << std::endl;
	}
	else if (bureaucrat.getGrade() > this->_gradeToSigned){
		std::cout << bureaucrat.getName() << " n'a pas pu signer " << this->getName() << " a cause de son grade" << std::endl;
		std::cout << "Signature du formulaire : " << this->_isSigned << std::endl;
	}
	else
		throw AForm::GradeTooLowException(_name);
}
