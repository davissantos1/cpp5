/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:01:20 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/22 19:17:23 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout	<< "Wrong usage, please type with no arguments:\n"
					<< "./form"
					<< std::endl;
		return (1);
	}
	else
	{
		std::cout << std::endl;

		std::cout	<< "========= FORM CREATION TEST ========="
					<< std::endl << std::endl;

		Bureaucrat boss("Boss", 1);
		Bureaucrat joe("Joe", 150);

		std::cout << boss << std::endl << std::endl;
		std::cout << joe << std::endl << std::endl;

		Form test1("test1", 30, 20);
		Form test2("test2", 1, 1);
		Form test3("test3", 150, 150);
		Form* test4 = new Form();

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << test3 << std::endl;
		std::cout << *test4 << std::endl;

		std::cout << std::endl;

		std::cout	<< "========= FORM ASSIGNMENT TEST ========="
					<< std::endl << std::endl; 

		std::cout << "test1 will become test2" << std::endl << std::endl;
		std::cout << test1 << std::endl;
		test1 = test2;
		std::cout << test1 << std::endl;
		
		std::cout << std::endl;

		std::cout	<< "========= FORM << OVERLOAD TEST ========="
					<< std::endl << std::endl; 

		std::cout << test2 << std::endl;
		std::cout << *test4 << std::endl;

		std::cout << std::endl;

		std::cout	<< "========= FORM EXCEPTION TEST ========="
					<< std::endl << std::endl;

		boss.signForm(test2);
		std::cout << std::endl;
		boss.signForm(*test4);
		std::cout << std::endl;
		std::cout << test2 << std::endl;
		std::cout << *test4 << std::endl;

		try
		{
			test3.beSigned(joe);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout	<< "========= DEFAULT HEAP DESTRUCTOR TEST ========="
					<< std::endl << std::endl; 

		std::cout << "Deleting test4..." << std::endl;
		delete (test4);

		std::cout << std::endl;
	}
	return (0);
}
