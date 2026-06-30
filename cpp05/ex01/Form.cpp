/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:06:37 by miparis           #+#    #+#             */
/*   Updated: 2026/06/04 11:33:31 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
/*								constructors & destructors				      */


Form::Form() : _name("_defaultForm"), _gradeSign(gradeLowest), _gradeExec(gradeLowest), _signed(false)
{
	std::cout << PURPLE << "(Def.) " << "Form created" << NC << std::endl;
}
Form:: Form(std::string const _name, unsigned int _gradeSign, unsigned int _gradeExec, bool _signed): _name(_name), _signed(_signed), _gradeExec(_gradeExec), _gradeSign(_gradeSign)
{
	if (_gradeSign > gradeLowest)
		throw Form::GradeTooLowException();
	if (_gradeSign < gradeHighest)
		throw Form::GradeTooHighException();
	if (_gradeExec > gradeLowest)
		throw Form::GradeTooLowException();
	if (_gradeExec < gradeHighest)
		throw Form::GradeTooHighException();
	std::cout << PURPLE << "(Custom) " << "Form created" << NC << std::endl;
}
Form:: Form(const Form& _copy): _name(_copy._name), _signed(_copy._signed), _gradeExec(_gradeExec), _gradeSign(_gradeSign)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << "Form created" << NC << std::endl;
}
Form& Form:: operator=(const Form& _copy)
{
	if (this != &_copy)
	{
		this->_signed = _copy._signed;
	}
	std::cout << PURPLE << "(Assign.) " << "Form created" << NC << std::endl;
	return (*this);
}

Form:: ~Form()
{
	std::cout << RED << "(Destruct.) " << "Form done" << NC << std::endl;
}


/*									getters										 */

const std::string &Form::getName() const
{
	return (this->_name);
}

unsigned int Form::getSignGrade() const
{
	return (this->_gradeSign);
}

unsigned int Form::getExecGrade() const
{
	return (this->_gradeExec);
}

bool Form::getStatus() const
{
	return (this->_signed);
}

/*									sign									 */

void Form::beSigned(const Bureaucrat& _bureaucrat)
{
	if (_bureaucrat.getGrade() >= this->_gradeSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}
	

std::ostream& operator<<(std::ostream& os, const Form& _form)
{
	os << "<" << _form.getName() << " form state: " << _form.getStatus() << ">, form grade to sign <" << _form.getSignGrade() << ">, form grade to execute <" << _form.getExecGrade() << ">." << std::endl;
    return (os);
}