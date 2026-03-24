/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:17:42 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/24 19:56:19 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): 
	AForm("Robotomy Request Form", 72, 45, "no target") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): 
	AForm("Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ):
	AForm(other) {}

RobotomyRequestForm& 	RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	if (this != &other)
		this->AForm::operator=(other);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::string name;
	
	this->checkRequirements(executor);
	name = this->getTarget();
	if (std::rand() % 2 == 0)
		std::cout << name << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy has failed!" << std::endl;
}
