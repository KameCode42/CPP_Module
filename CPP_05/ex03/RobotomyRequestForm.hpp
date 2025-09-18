/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:07:01 by david             #+#    #+#             */
/*   Updated: 2025/09/18 11:28:42 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& other);
		virtual ~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm const& roboto);

#endif
