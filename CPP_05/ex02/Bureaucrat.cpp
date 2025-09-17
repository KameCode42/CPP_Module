/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:54:36 by david             #+#    #+#             */
/*   Updated: 2025/09/17 16:01:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*-------------------------------constructeur--------------------------------*/

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException(_name);
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException(_name);
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : _name(src._name), _grade(src._grade){
}

/*-------------------------------operateur-------------------------------------*/

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& other){
	if (this != &other){
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bureaucrat){
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

/*-------------------------------destructeur-----------------------------------*/

Bureaucrat::~Bureaucrat(){
	std::cout << "Le Bureaucrat " << this->_name << " est detruit" << std::endl;
}

/*-------------------------------getter----------------------------------------*/

const std::string	Bureaucrat::getName(void)const{
	return this->_name;
}

int	Bureaucrat::getGrade(void)const{
	return this->_grade;
}

/*-------------------------------ft_membre-------------------------------------*/

void	Bureaucrat::increment(){
	std::cout << "incrementation :" << std::endl;
	this->_grade --;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException(_name);
}

void	Bureaucrat::decrement(){
	std::cout << "decrementation :" << std::endl;
	this->_grade ++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException(_name);
}

void	Bureaucrat::signForm(AForm& form){
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const & form) const{
	if (form.getIsSigned() == true && this->getGrade() <= form.getGradeToExecute())
	{
		form.execute(*this);
		std::cout << this->getName() << " a pu executer " << form.getName() << std::endl;
	}
	else
	{
		std::cout << this->getName() << " n'a pas pu executer " << form.getName() << std::endl;
		throw Bureaucrat::GradeTooLowException(this->getName());
	}
}
