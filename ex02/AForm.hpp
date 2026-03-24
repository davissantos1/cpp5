/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:51:23 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/24 20:47:03 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class	AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		const int			_requiredGradeToSign;
		const int			_requiredGradeToExecute;
		bool				_isSigned;
	public:
		AForm();
		virtual	~AForm();
		AForm( const AForm& other );
		AForm&	operator=( const AForm& other );
		AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target); 
		const std::string&	getName() const;
		const std::string&	getTarget() const;
		int					getRequiredGradeToSign() const;
		int					getRequiredGradeToExecute() const;
		bool				getIsSigned() const;
		void				beSigned( const Bureaucrat& bureaucrat );
		virtual void		execute(Bureaucrat const & executor) const = 0;
		void				checkRequirements( const Bureaucrat& bureaucrat ) const;
		class GradeTooHighException: public std::exception
		{
			virtual const char*	what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class NotSignedException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
