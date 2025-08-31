/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:32:30 by david             #+#    #+#             */
/*   Updated: 2025/08/31 15:08:37 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*-------------------------------constructeur--------------------------------*/

Form::Form(const std::string name, const int gradeToSigned, const int gradeToExecute) :
_name(name), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute){
	this->_isSigned = false;
	if (this->_gradeToSigned < 1 || this->_gradeToExecute < 1)
	{
		throw Form::GradeTooHighException(_name);
	}
	else if (this->_gradeToSigned > 150 || this->_gradeToExecute > 150)
	{
		throw Form::GradeTooLowException(_name);
	}
}

Form::Form(Form const& src) :
_name(src._name), _gradeToSigned(src._gradeToSigned), _gradeToExecute(src._gradeToExecute), _isSigned(src._isSigned){
}

/*-------------------------------operateur-------------------------------------*/

Form&	Form::operator=(Form const& other){
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, Form const& Form){
	std::cout << "Nom formulaire : " << Form.getName() << std::endl;
	std::cout << "Grade requis pour signer : " << Form.getGradeToSigned() << std::endl;
	std::cout << "Grade requis pour executer : " << Form.getGradeToExecute() << std::endl;
	std::cout  << "Est-il signe (0 = non signe, 1 = signe) ? " << Form.getIsSigned() << std::endl;
	return os;
}

/*-------------------------------destructeur-----------------------------------*/

Form::~Form(){
	std::cout << "Le formulaire " << this->_name << " est detruit" << std::endl;
}

/*-------------------------------getter----------------------------------------*/

const std::string	Form::getName()const{
	return this->_name;
}

bool	Form::getIsSigned()const{
	return this->_isSigned;
}

const int	Form::getGradeToSigned()const{
	return this->_gradeToSigned;
}

const int	Form::getGradeToExecute()const{
	return this->_gradeToExecute;
}

/*-------------------------------ft membre-------------------------------------*/

void	Form::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= this->_gradeToSigned){
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " a pu signer " << this->getName() << std::endl;
		std::cout << "Etat du formulaire : " << this->_isSigned << std::endl;
	}
	else if (bureaucrat.getGrade() > this->_gradeToSigned){
		std::cout << bureaucrat.getName() << " n'a pas pu signer " << this->getName() << " a cause de son grade" << std::endl;
		std::cout << "Etat du formulaire : " << this->_isSigned << std::endl;
	}
	else
		throw Form::GradeTooLowException(_name);
}
