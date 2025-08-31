/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:54:36 by david             #+#    #+#             */
/*   Updated: 2025/08/31 15:07:32 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& Bureaucrat){
	std::cout << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
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

void	Bureaucrat::increment()
{
	std::cout << "incrementation :" << std::endl;
	this->_grade --;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException(_name);
}

void	Bureaucrat::decrement()
{
	std::cout << "decrementation :" << std::endl;
	this->_grade ++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException(_name);
}

void	Bureaucrat::signForm(Form& form){
	form.beSigned(*this);
}
