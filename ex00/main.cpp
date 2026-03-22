/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:01:20 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/22 11:41:32 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout	<< "Wrong usage, please type with no arguments:\n"
					<< "./bureaucrat" 
					<< std::endl;
		return (1);
	}
	else
	{
		std::cout << std::endl;

		std::cout	<< "========= BUREAUCRAT CREATION TEST ========="
					<< std::endl << std::endl; 
		std::cout << "Creating Boss, test and dude\n";
		Bureaucrat boss("Boss", 1);
		Bureaucrat test("Test", 100);
		Bureaucrat *dude = new Bureaucrat();
		
		std::cout << boss << std::endl;
		std::cout << test << std::endl;
		std::cout << *dude << std::endl;

		std::cout << std::endl;

		std::cout	<< "========= BUREAUCRAT ASSIGNMENT TEST ========="
					<< std::endl << std::endl; 

		std::cout << *dude << " I will get test's grade\n";
		*dude = test;
		std::cout << *dude  << std::endl;

		std::cout << std::endl;

		std::cout	<< "========= BUREAUCRAT << OVERLOAD TEST ========="
					<< std::endl << std::endl; 
		
		std::cout << test << "I'm test" << std::endl;
		std::cout << boss << "I'm boss" << std::endl;

		std::cout << std::endl;

		std::cout	<< "========= BUREAUCRAT EXCEPTION TEST ========="
					<< std::endl << std::endl; 
		try
		{
			Bureaucrat wrong("Jack", 151);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
 
		try
		{
			Bureaucrat wrong2("Joe", 0);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout	<< "========= DEFAULT HEAP DESTRUCTOR TEST ========="
					<< std::endl << std::endl; 

		std::cout << "Deleting dude..." << std::endl;
		delete (dude);

		std::cout << std::endl;
	}
	return (0);
}
