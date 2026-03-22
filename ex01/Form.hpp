/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:51:23 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/22 19:03:10 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	_name;
		const int			_requiredGradeToSign;
		const int			_requiredGradeToExecute;
		bool				_isSigned;
	public:
		Form();
		~Form();
		Form( const Form& other );
		Form(std::string name, int gradeToSign, int gradeToExecute); 
		Form&	operator=( const Form& other );
		const std::string&	getName() const;
		int			getRequiredGradeToSign() const;
		int			getRequiredGradeToExecute() const;
		bool				getIsSigned();
		void				beSigned(const Bureaucrat& bureaucrat);
		class GradeTooHighException: public std::exception
		{
			virtual const char*	what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Form& form);

#endif
