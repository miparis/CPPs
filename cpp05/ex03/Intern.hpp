/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:59:43 by miparis           #+#    #+#             */
/*   Updated: 2026/06/04 12:00:29 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	AForm* createShruberry(std::string _target);
	AForm* createRobotomy(std::string _target);
	AForm* createPresidential(std::string _target);
	AForm* (Intern::*pointerFunction[3])(std::string _target);  //This variable will point to wathever member function for the creation of the form we can use


	public:
	Intern();
	Intern(const Intern& _copy);
	Intern& operator=(const Intern& _copy);
	virtual ~Intern();
	AForm* makeForm(std::string _formName, std::string _target);
};