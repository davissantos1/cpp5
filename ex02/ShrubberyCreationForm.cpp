/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:17:42 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/24 20:48:47 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): 
	AForm("Shruberry Creation Form", 145, 137, "no target") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): 
	AForm("Shruberry Creation Form", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ):
	AForm(other) {}

ShrubberyCreationForm& 	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	if (this != &other)
		this->AForm::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string name;
	std::fstream file;

	this->checkRequirements(executor);
	name = this->getTarget() + "_shrubbery";
	file.open(name.c_str(), std::fstream::out);
	file << " ⢀⢀⣼⣦⠀⠀⣠⣿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣆\n⠀⠒⣿⣿⣿⠓⠀⠀⠻⣿⣿⠀⢀⣴⣿⣦⡀⠀⢀⣾⣦⠘⢿⣿⣧\n ⢀⣴⣿⡿⠃⡄⠈⠻⣿⣟⣉⣀⠉⣽⡿⠋⠡⠴⣿⣿⣿⠓⠀⠙⢇\n⠀⠿⣿⠟⢁⣾⣿⣦⣀⠘⠿⠟⢁⣼⣿⣿⣷⠂⣴⣿⣿⣿⣆⠘⢶⣶⣿⠶⠤\n ⠀⣀⣀⡀⢉⣿⣿⣿⡍⠀⢀⣀⠙⢻⠿⢋⣤⣾⣿⣿⣿⣿⣿⣷⣄⠙⢿⣦⡀⠀\n⠀⠟⠋⣠⣾⣿⣿⣿⣿⣦⣌⠉⠠⣤⣤⣤⡌⢙⣿⣿⣿⣿⣿⣿⠛⠛⠂⢈⣙\n⠀⣉⡉⣹⣿⣿⣿⣿⣏⠉⣉⣀⣈⠙⠋⣠⣿⣿⣿⣿⣿⣿⣿⣆⠙⠛⠛⠛\n ⠋⣴⣿⣿⣿⣿⣿⣿⣷⣌⠉⢁⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄\n⠀⠴⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠦⠈⣙⠛⠛⠛⠛⠛⠛⠛⠛⣉⣉\n⠀⣦⣤⡄⢉⣉⣉⣉⠉⣡⣤⠀⠀⠀⣿⣿⣷⠀⢰⣿⣿⡇⢸⣿⣿\n ⠀⣿⣿⡇⣸⣿⣿⣿⡄⢻⣿⠀⠀⠀⣿⣿⣿⠀⢸⣿⣿⡇⢸⣿⣿\n⠀⣿⣿⠁⣿⣿⣿⣿⡇⠸⠿⠀⠀⠀⣿⣿⣿⠀⢸⣿⣿⣇⠸⣿⣿\n ⠛⠛⠀⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠉⠉⠉⠀⢸⣿⣿⣿⠀⠿⠿ \n⠛⠛⠛⠛⠃";
	file.close();
}
