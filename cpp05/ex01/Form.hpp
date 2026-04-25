/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form
{
	private:
	std::string const _name;
	unsigned int _gradeSign;
	unsigned int _gradeExec;
	bool _signed;

	public:
	Form();
	Form(std::string const _name, unsigned int _gradeSign, unsigned int _gradeExec, bool _signed);
	Form(const Form& _copy);
	Form& operator=(const Form& _copy);
	virtual ~Form();
	
	const std::string &getName() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;
	bool getStatus() const;
	
	void beSigned(const Bureaucrat& _bureaucrat);
	
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
};

std::ostream& operator<<(std::ostream& os, const Form& _form);