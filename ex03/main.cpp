/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:01:20 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/25 12:08:01 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(int ac, char **av)
{
	(void)av;
	std::srand(std::time(NULL));
	if (ac != 1)
	{
		std::cout	<< "Wrong usage, please type with no arguments:\n"
					<< "./intern"
					<< std::endl;
		return (1);
	}
	else
	{
		std::cout << std::endl;

		std::cout	<< "========= NEW FORMS CREATION TEST ========="
					<< std::endl << std::endl;

		Bureaucrat	president("El Presidente", 1);
		Bureaucrat	loser("El Perdedor", 150);
		Intern		johnny;

		std::cout << president << std::endl << std::endl;
		std::cout << loser << std::endl << std::endl;
		std::cout << "Created Intern Johnny" << std::endl;

		AForm* tree = johnny.makeForm("shrubbery creation", "ASCII Tree");
		AForm* robotomization = johnny.makeForm("robotomy request", "El Perdedor");
		AForm* pardon = johnny.makeForm("presidential pardon", "Johnny");

		std::cout << *tree << std::endl;
		std::cout << *robotomization << std::endl;
		std::cout << *pardon << std::endl;

		std::cout << std::endl;

		std::cout	<< "========= INTERN MAKES WRONG FORM TEST ========="
					<< std::endl << std::endl; 
		try
		{
			AForm* test = johnny.makeForm("jasdlkjsaldkjsal	", "test");
			(void) test;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << std::endl;
		std::cout	<< "========= EXECUTE FORM TEST ========="
					<< std::endl << std::endl; 

		president.signForm(*tree);
		president.signForm(*robotomization);
		president.signForm(*pardon);
		president.executeForm(*tree);
		president.executeForm(*robotomization);
		president.executeForm(*pardon);
		
		std::cout << std::endl;

		std::cout	<< "========= EXECUTE WRONG FORM TEST ========="
					<< std::endl << std::endl; 
	
		loser.executeForm(*tree);
		loser.executeForm(*robotomization);
		loser.executeForm(*pardon);

		std::cout << std::endl;
		std::cout	<< "========= DEFAULT HEAP DESTRUCTOR TEST ========="
					<< std::endl << std::endl; 

		std::cout << "Deleting Forms..." << std::endl;
		delete (tree);
		delete (robotomization);
		delete (pardon);

		std::cout << std::endl;
	}
	return (0);
}
