/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:52:17 by miparis           #+#    #+#             */
/*   Updated: 2026/04/25 17:42:52 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define gradeLowest	150
#define gradeHighest	1

class AForm
{
	private:
	std::string const _name;
	unsigned int const _gradeSign;
	unsigned int const _gradeExec;
	bool _signed;

	public:
	AForm();
	AForm(std::string const _name, unsigned int const _gradeSign, unsigned int const _gradeExec, bool _signed);
	AForm(const AForm& _copy);
	AForm& operator=(const AForm& _copy);
	virtual ~AForm();
	
	const std::string &getName() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;
	bool getStatus() const;
	
	void beSigned(const Bureaucrat& _bureaucrat);
	void checkExecution(Bureaucrat const & executor) const;
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form grade too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form grade too low");
			}
	};

	/*									NEW EXCEPTION						*/
	class FormNotSignedException : public std::exception 
	{
		virtual const char* what() const throw()
		{
			return ("Form not signed");
		}
	};
	
};

std::ostream& operator<<(std::ostream& os, const AForm& _AForm);