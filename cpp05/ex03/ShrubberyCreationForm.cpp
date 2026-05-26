/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:42:15 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 11:25:23 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, false), _target("default_target")
{
	std::cout << PURPLE << "(Def.) " << this->getName() << " ready!" << NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _copy) : AForm(_copy), _target(_copy._target)
{
	std::cout << PURPLE << "(Copy) " << this->getName() << " ready!" << NC << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& _copy)
{
if (this != &_copy)
	{
		AForm::operator=(_copy);
		this->_target = _copy._target;
	}
	std::cout << PURPLE << "(Assign op.) " << this->getName() << " ready!" << NC << std::endl;
	return (*this);
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, false), _target(target)
{
	std::cout << PURPLE << "(Target) " << this->getName() << " ready!" << NC << std::endl;
}
ShrubberyCreationForm:: ~ShrubberyCreationForm()
{
	std::cout << RED << "(Destruct.) " << this->getName() << " done!" << NC << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor); 

    std::cout << RED << "Creating shrubbery at " << this->_target << "_shrubbery..." << NC << std::endl;
	this->createTree();
}

void ShrubberyCreationForm::createTree() const
{
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream outFile(fileName.c_str());

	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not create file " << fileName << std::endl;
		return;
	}

	outFile << "    /~~   ~~\\" << std::endl;
	outFile << " /~~         ~~\\" << std::endl;
	outFile << "{               }" << std::endl;
	outFile << " \\  _-     -_  /" << std::endl;
	outFile << "   ~  \\\\ //  ~" << std::endl;
	outFile << "      _||_" << std::endl;
	outFile << "     {____}" << std::endl;
	outFile << std::endl;
	outFile << "       _-_" << std::endl;
	outFile << "    /~~   ~~\\" << std::endl;
	outFile << " /~~         ~~\\" << std::endl;
	outFile << "{               }" << std::endl;
	outFile << " \\  _-     -_  /" << std::endl;
	outFile << "   ~  \\\\ //  ~" << std::endl;
	outFile << "      _||_" << std::endl;
	outFile << "     {____}" << std::endl;

	outFile.close();
	
	std::cout << GREEN << "Shrubbery successfully planted at " << fileName << NC << std::endl;
}