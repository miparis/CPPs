/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:06:37 by miparis           #+#    #+#             */
/*   Updated: 2026/04/25 17:26:01 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
/*								constructors & destructors				      */


AForm::AForm() : _name("_defaultAForm"), _gradeSign(gradeLowest), _gradeExec(gradeLowest), _signed(false)
{
	std::cout << PURPLE << "(Def.) " << "AForm created" << NC << std::endl;
}
AForm:: AForm(std::string const _name, unsigned int _gradeSign, unsigned int _gradeExec, bool _signed): _name(_name), _signed(_signed)
{
	if (_gradeSign > gradeLowest)
		throw AForm::GradeTooLowException();
	if (_gradeSign < gradeHighest)
		throw AForm::GradeTooHighException();
	if (_gradeExec > gradeLowest)
		throw AForm::GradeTooLowException();
	if (_gradeExec < gradeHighest)
		throw AForm::GradeTooHighException();
	this->_gradeExec = _gradeExec;
	this->_gradeSign = _gradeSign;
	std::cout << PURPLE << "(Custom) " << "AForm created" << NC << std::endl;
}
AForm:: AForm(const AForm& _copy): _name(_copy._name), _signed(_copy._signed)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << "AForm created" << NC << std::endl;
}
AForm& AForm:: operator=(const AForm& _copy)
{
	if (this != &_copy)
	{
		this->_gradeExec = _copy._gradeExec;
		this->_gradeSign = _copy._gradeSign;
	}
	std::cout << PURPLE << "(Assign.) " << "AForm created" << NC << std::endl;
	return (*this);
}

AForm:: ~AForm()
{
	std::cout << RED << "(Destruct.) " << "AForm done" << NC << std::endl;
}


/*									getters										 */

const std::string &AForm::getName() const
{
	return (this->_name);
}

unsigned int AForm::getSignGrade() const
{
	return (this->_gradeSign);
}

unsigned int AForm::getExecGrade() const
{
	return (this->_gradeExec);
}

bool AForm::getStatus() const
{
	return (this->_signed);
}

/*									sign									 */

void AForm::beSigned(const Bureaucrat& _bureaucrat)
{
	if (_bureaucrat.getGrade() >= this->_gradeSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}
	

std::ostream& operator<<(std::ostream& os, const AForm& _AForm)
{
	os << "<" << _AForm.getName() << " AForm state: " << _AForm.getStatus() << ">, AForm grade to sign <" << _AForm.getSignGrade() << ">, AForm grade to execute <" << _AForm.getExecGrade() << ">." << std::endl;
    return (os);
}

/* 						NEW METHODS TO CHECK HEREDITARY RANGES				*/
void AForm::checkExecution(Bureaucrat const & executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
}