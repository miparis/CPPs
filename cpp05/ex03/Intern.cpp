/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:59:39 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 12:43:22 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern:: Intern()
{
	std::cout << PURPLE << "(Def.) " << "Intern created" << NC << std::endl;
}
Intern:: Intern(const Intern& _copy)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << "Intern created" << NC << std::endl;
}
Intern& Intern::operator=(const Intern& _copy)
{
	if (this != &_copy)
		*this = _copy;
	std::cout << PURPLE << "(Assign.) " << "Intern created" << NC << std::endl;
	return (*this);
}

Intern:: ~Intern()
{
	std::cout << RED << "(Destruct.) " << "Intern done" << NC << std::endl;
}

AForm* Intern::makeForm(std::string _formName, std::string _target)
{
	std::string _formNames[3] = {
    	"shrubbery creation",
   		"robotomy request",
    	"presidential pardon"
	};

	pointerFunction[0] = &Intern::createShruberry;
	pointerFunction[1] = &Intern::createRobotomy;
	pointerFunction[2] = &Intern::createPresidential;

	for (int i = 0; i < 3; i++)
	{
		if (_formNames[i] == _formName)
		{
			std::cout << BLUE << "Intern creates <" <<  _formNames[i] << ">" << NC << std::endl;
			return (this->*pointerFunction[i])(_target);
		}
	}
	std::cerr << RED << "Solicited form <" << _formName<< "> doesnt exist" << NC << std::endl;
	return (NULL);
}

AForm* Intern::createShruberry(std::string _target)
{
	return (new ShrubberyCreationForm(_target));
}
AForm* Intern::createRobotomy(std::string _target)
{
	return (new RobotomyRequestForm(_target));
}
AForm* Intern::createPresidential(std::string _target)
{
	return (new PresidentialPardonForm(_target));
}