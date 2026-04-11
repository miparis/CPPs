/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:20:20 by miparis           #+#    #+#             */
/*   Updated: 2026/04/11 19:54:49 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*								constructors & destructors				      */

Bureaucrat:: Bureaucrat() : _name("_random"), _grade(gradeLowest)
{
	std::cout << PURPLE << "(Def.) " << "Bureaucrat created" << NC << std::endl;
}
Bureaucrat:: Bureaucrat(std::string _nName, int _nGrade): _name(_nName)
{
	if (_nGrade > gradeLowest)
		throw Bureaucrat::GradeTooLowException();
	if (_nGrade < gradeHighest)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = _nGrade;
	std::cout << PURPLE << "(Custom) " << "Bureaucrat created" << NC << std::endl;
}
Bureaucrat:: Bureaucrat(const Bureaucrat& _copy) : _name(_copy._name)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << "Bureaucrat created" << NC << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& _copy)
{
	if (this != &_copy)
		this->_grade = _copy._grade;
	std::cout << PURPLE << "(Assign.) " << "Bureaucrat created" << NC << std::endl;
	return (*this);
}

Bureaucrat:: ~Bureaucrat()
{
	std::cout << RED << "(Destruct.) " << "Bureaucrat done" << NC << std::endl;
}
/*									getters										 */
const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/*									increment & decrement						 */
void Bureaucrat::incrementGrade(int _value)
{
	int _new = this->_grade - _value;
	if (_new < gradeHighest)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		this->_grade -= _value;
		std::cout << BLUE << "Bureaucrat has levelled up!" << NC << std::endl;
	}
}
void Bureaucrat::decrementGrade(int _value)
{
	int _new = this->_grade + _value;
	if (_new > gradeLowest)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->_grade += _value;
		std::cout << BLUE << "Bureaucrat has levelled down!" << NC << std::endl;
	}
}
/*									operator << 								 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& _bureaucrat)
{
	os << "<" << _bureaucrat.getName() << ">, bureaucrat grade <" << _bureaucrat.getGrade() << ">." << std::endl;
    return (os);
}