/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:38:43 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/18 14:49:08 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os	<< bureaucrat.getName() << ", "
		<< "bureaucrat grade "
		<< bureaucrat.getGrade() 
		<< ".";
	return (os);
}

Bureaucrat::Bureaucrat(): _name("John"), _grade(150) {}

Bureaucrat::Bureaucrat( const Bureaucrat& other ): _name(other._name)
{
	if (this != &other)
		*this = other;
}

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&		Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
	{
		this->_grade++;
		throw Bureaucrat::GradeTooHighException();
	}
}

void			Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
	{
		this->_grade--;
		throw Bureaucrat::GradeTooLowException();
	}
}
