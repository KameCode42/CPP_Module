/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:46:40 by david             #+#    #+#             */
/*   Updated: 2025/09/17 14:10:45 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& other);
		virtual ~ShrubberyCreationForm();

		virtual void	execute(Bureaucrat const & executor) const;


	private:
		std::string	_target;
};

std::ostream&	operator<<(std::ostream& os, ShrubberyCreationForm const& shrubbery);

#endif
