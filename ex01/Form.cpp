/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:12:44 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/22 19:03:52 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
	_name("Default"),
	_requiredGradeToSign(100),
	_requiredGradeToExecute(100),
	_isSigned(false)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):
	_name(name),
	_requiredGradeToSign(gradeToSign),
	_requiredGradeToExecute(gradeToExecute),
	_isSigned(false)
{}

Form::Form( const Form& other ): 
	_name(other._name),
	_requiredGradeToSign(other._requiredGradeToSign),
	_requiredGradeToExecute(other._requiredGradeToExecute)
{
	if (this != &other)
		*this = other;
}

Form&	Form::operator=( const Form& other )
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

const std::string&	Form::getName() const
{
	return (this->_name);
}

int			Form::getRequiredGradeToSign() const
{
	return (this->_requiredGradeToSign);
}

int			Form::getRequiredGradeToExecute() const
{
	return (this->_requiredGradeToExecute);
}

bool				Form::getIsSigned()
{
	return (this->_isSigned);
}

void				Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->_requiredGradeToSign)
		this->_isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

std::ostream&	operator<<(std::ostream& os, Form& form)
{
	os	<< "FORM'S INFORMATION" << std::endl
		<< "Name: " << form.getName() << std::endl
		<< "Signed: " << form.getIsSigned() << std::endl
		<< "Required Grade To Sign: " << form.getRequiredGradeToSign() << std::endl
		<< "Required Grade To Execute: " << form.getRequiredGradeToExecute() << std::endl;
	return (os);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("needed grade is lower than provided!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("needed grade is higher than provided!");
}
