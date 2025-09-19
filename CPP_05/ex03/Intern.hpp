/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:40:35 by david             #+#    #+#             */
/*   Updated: 2025/09/19 11:02:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern const& src);
		Intern&	operator=(Intern const& other);
		~Intern();
		
		AForm*	makeForm(std::string form, std::string target);
		
		class	FormNoExist : public std::exception
		{
			virtual const char* what() const throw()
			{
				return("Le formulaire n'existe pas");
			}
		};
};

#endif
