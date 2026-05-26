/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:04:08 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 11:30:32 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, false), _target("default_target")
{
	std::cout << PURPLE << "(Def.) " << this->getName() << " ready!" << NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& _copy) : AForm(_copy), _target(_copy._target)
{
	std::cout << PURPLE << "(Copy) " << this->getName() << " ready!" << NC << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& _copy)
{
if (this != &_copy)
	{
		AForm::operator=(_copy);
		this->_target = _copy._target;
	}
	std::cout << PURPLE << "(Assign op.) " << this->getName() << " ready!" << NC << std::endl;
	return (*this);
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, false), _target(target)
{
	std::cout << PURPLE << "(Target) " << this->getName() << " ready!" << NC << std::endl;
}
RobotomyRequestForm:: ~RobotomyRequestForm()
{
	std::cout << RED << "(Destruct.) " << this->getName() << " done!" << NC << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->checkExecution(executor); 

    std::cout << BLUE << "** Zzzzzzzt .... Zzzzt **" << NC << std::endl;
	if (rand()% 2 == 0)
		std::cout << GREEN << "<" << this->_target << "> has been robotomized successfully " << NC << std::endl;
	else
		std::cout << RED << "<" << this->_target << "> robotomy failed" << NC << std::endl;
}