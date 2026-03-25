/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:02:25 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/25 12:04:46 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

enum	e_form
{
	SHRUBBERY,
	ROBOTOMY,
	PARDON,
	OTHER
};

class	Intern
{
	private:
		AForm*	makeShrubbery( std::string target );
		AForm*	makeRobotomy( std::string target );
		AForm*	makePardon( std::string target );
	public:
		Intern();
		~Intern();
		Intern( const Intern& other );
		Intern&	operator=( const Intern& other );
		AForm*	makeForm( std::string formName, std::string targetForm );
		class WrongFormNameException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

#endif
