/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:12:44 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/24 20:46:54 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():
	_name("Default"),
	_target("no target"),
	_requiredGradeToSign(100),
	_requiredGradeToExecute(100),
	_isSigned(false)
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target):
	_name(name),
	_target(target),
	_requiredGradeToSign(gradeToSign),
	_requiredGradeToExecute(gradeToExecute),
	_isSigned(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighException());
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowException());
}

AForm::AForm( const AForm& other ): 
	_name(other._name),
	_target(other._target),
	_requiredGradeToSign(other._requiredGradeToSign),
	_requiredGradeToExecute(other._requiredGradeToExecute),
	_isSigned(other._isSigned)
{}

AForm&	AForm::operator=( const AForm& other )
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

const std::string&	AForm::getName() const
{
	return (this->_name);
}

const std::string&	AForm::getTarget() const
{
	return (this->_target);
}

int			AForm::getRequiredGradeToSign() const
{
	return (this->_requiredGradeToSign);
}

int			AForm::getRequiredGradeToExecute() const
{
	return (this->_requiredGradeToExecute);
}

bool				AForm::getIsSigned() const
{
	return (this->_isSigned);
}

void				AForm::beSigned(const Bureaucrat& bureaucrat)
{
	int signGrade = this->_requiredGradeToSign;
	int	bureauGrade = bureaucrat.getGrade();

	if (bureauGrade <= signGrade)
		this->_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os	<< "FORM'S INFORMATION" << std::endl
		<< "Name: " << form.getName() << std::endl
		<< "Signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl
		<< "Required Grade To Sign: " << form.getRequiredGradeToSign() << std::endl
		<< "Required Grade To Execute: " << form.getRequiredGradeToExecute() << std::endl;
	return (os);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("needed grade is lower than provided!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("needed grade is higher than provided!");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("the form is not signed, sign it and try again!");
}

void		AForm::checkRequirements( const Bureaucrat& bureaucrat ) const
{
	int	execBureau = bureaucrat.getGrade();
	int	execForm = this->_requiredGradeToExecute;

	if (execBureau > execForm)
		throw (GradeTooLowException());
	if (!this->_isSigned)
		throw (NotSignedException());
}
