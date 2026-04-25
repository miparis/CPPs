/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:02 by miparis           #+#    #+#             */
/*   Updated: 2026/04/25 17:46:19 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

#define gradeLowest	150
#define gradeHighest	1

class Form;

class Bureaucrat
{
	protected:
	std::string const _name;
	unsigned int _grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string _name, unsigned int _grade);
	Bureaucrat(const Bureaucrat& _copy);
	Bureaucrat& operator=(const Bureaucrat& _copy);
	virtual ~Bureaucrat();
	
	const std::string &getName() const;
	unsigned int getGrade() const;
	
	void incrementGrade(unsigned int _value);
	void decrementGrade(unsigned int _value);

	void signForm(Form& _form);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Bureaucrat grade too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Bureaucrat grade too low");
			}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& _bureaucrat);
