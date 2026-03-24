/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:01:20 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/24 20:33:02 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
					<< "./makeform"
					<< std::endl;
		return (1);
	}
	else
	{
		std::cout << std::endl;

		std::cout	<< "========= NEW FORMS CREATION TEST ========="
					<< std::endl << std::endl;

		Bureaucrat president("El Presidente", 1);
		Bureaucrat joe("Joe", 75);
		Bureaucrat loser("El Perdedor", 150);

		std::cout << president << std::endl << std::endl;
		std::cout << joe << std::endl << std::endl;
		std::cout << loser << std::endl << std::endl;

		AForm* tree = new ShrubberyCreationForm("tree");
		AForm* robotomization = new RobotomyRequestForm(loser.getName());
		AForm* pardon = new PresidentialPardonForm(joe.getName());

		std::cout << *tree << std::endl;
		std::cout << *robotomization << std::endl;
		std::cout << *pardon << std::endl;

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

		std::cout << "Deleting Bureaucrats..." << std::endl;
		delete (tree);
		delete (robotomization);
		delete (pardon);

		std::cout << std::endl;
	}
	return (0);
}
