/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:54:12 by david             #+#    #+#             */
/*   Updated: 2025/09/26 16:31:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat&	operator=(Bureaucrat const& other);
		~Bureaucrat();

		const std::string	getName(void)const;
		int					getGrade(void)const;
		void				increment();
		void				decrement();
		void				signForm(AForm& form);
		void				executeForm(AForm const & form) const;

		class	GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const std::string& name) : _msg(name + " : Le grade est trop haut"){
				}
			private:
				std::string	_msg;
			public:
			virtual const char* what() const throw()
			{
				return _msg.c_str();
			}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(const std::string& name) : _msg(name + " : Le grade est trop bas"){
				}
			private:
				std::string	_msg;
			public:
			virtual const char* what() const throw()
			{
				return _msg.c_str();
			}
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif
