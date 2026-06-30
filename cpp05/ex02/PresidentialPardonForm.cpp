/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:28:04 by miparis           #+#    #+#             */
/*   Updated: 2026/06/04 11:41:07 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, false), _target("default_target")
{
	std::cout << PURPLE << "(Def.) " << this->getName() << " ready!" << NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& _copy) : AForm(_copy), _target(_copy._target)
{
	std::cout << PURPLE << "(Copy) " << this->getName() << " ready!" << NC << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& _copy)
{
if (this != &_copy)
	{
		AForm::operator=(_copy);
		this->_target = _copy._target;
	}
	std::cout << PURPLE << "(Assign op.) " << this->getName() << " ready!" << NC << std::endl;
	return (*this);
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, false), _target(target)
{
	std::cout << PURPLE << "(Target) " << this->getName() << " ready!" << NC << std::endl;
}
PresidentialPardonForm:: ~PresidentialPardonForm()
{
	std::cout << RED << "(Destruct.) " << this->getName() << " done!" << NC << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor); 

  	std::cout << GREEN << "<" << this->_target << "> has been pardoned by Zaphod Beeblebrox." << NC << std::endl;
}