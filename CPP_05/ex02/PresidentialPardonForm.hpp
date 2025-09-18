/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:09:12 by david             #+#    #+#             */
/*   Updated: 2025/09/18 11:33:41 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& other);
		virtual ~PresidentialPardonForm();

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm const& presidential);

#endif
