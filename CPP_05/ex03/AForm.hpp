/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:32:20 by david             #+#    #+#             */
/*   Updated: 2025/09/17 15:02:40 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(const std::string name, const int gradeToSigned, const int gradeToExecute);
		AForm(AForm const& src);
		AForm&	operator=(AForm const& other);
		virtual ~AForm();

		const std::string	getName()const;
		bool				getIsSigned()const;
		const int			getGradeToSigned()const;
		const int			getGradeToExecute()const;
		void				beSigned(Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class	GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(std::string name) : _msg(name + " Le grade est trop haute"){
				}
			private:
				const std::string	_msg;
			public:
				virtual const char* what() const throw()
				{
					return _msg.c_str();
				}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(std::string name) : _msg(name + " Le grade est trop bas"){
				}
			private:
				const std::string	_msg;
			public:
				virtual const char* what() const throw()
				{
					return _msg.c_str();
				}
		};
	
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSigned;
		const int			_gradeToExecute;
};

std::ostream&	operator<<(std::ostream& os, AForm const& Aform);

#endif
