/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:08:46 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/25 12:05:51 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern( const Intern& other ) 
{
	(void) other;
}

Intern&	Intern::operator=( const Intern& other )
{
	(void) other;
	return (*this);
}

AForm*	Intern::makeShrubbery( std::string target )
{
	std::cout << "Intern creates shrubbery creation form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomy( std::string target )
{
	std::cout << "Intern creates robotomy request form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePardon( std::string target )
{
	std::cout << "Intern creates presidential pardon form" << std::endl;
	return (new PresidentialPardonForm(target));
}

const char*	Intern::WrongFormNameException::what() const throw()
{
	return ("wrong form name provided, try again!");
}

AForm*	Intern::makeForm( std::string formName, std::string targetForm )
{
	enum e_form input = OTHER;

	AForm* (Intern::*methods[]) (std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePardon
	};
	
	input = ("shrubbery creation" == formName) ? SHRUBBERY : input;
	input = ("robotomy request" == formName) ? ROBOTOMY : input;
	input = ("presidential pardon" == formName) ? PARDON : input;

	switch (input)
	{
		case SHRUBBERY:
			return (this->*methods[SHRUBBERY])(targetForm);
		case ROBOTOMY:
			return (this->*methods[ROBOTOMY])(targetForm);
		case PARDON:
			return (this->*methods[PARDON])(targetForm);
		default:
			throw (Intern::WrongFormNameException());
	}
}
