/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:02 by miparis           #+#    #+#             */
/*   Updated: 2026/02/28 12:24:42 by miparis          ###   ########.fr       */
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

class Bureaucrat
{
	public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& _copy);
	Bureaucrat operator=(const Bureaucrat& _copy);
	virtual ~Bureaucrat();
	//getName() and getGrade(). one returns the const name the other the value
	//function increnent & decrement grade
	//1 (highest possible grade) to 150 (lowest possible grade).
	//If the grade goes out of range, both functions must throw the same exceptions as the constructor.
	protected:
	std::string const name;
	int grade;
};