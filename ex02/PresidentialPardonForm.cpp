/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:33:39 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/25 10:58:03 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm("presidential pardon", 25, 5, "no target") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): 
	AForm("presidential pardon", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ):
	AForm(other) {}

PresidentialPardonForm& 	PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	if (this != &other)
		this->AForm::operator=(other);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::string name;

	this->checkRequirements(executor);
	name = this->getTarget();
	std::cout	<< name
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}
