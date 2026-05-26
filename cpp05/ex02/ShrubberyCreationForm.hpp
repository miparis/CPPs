/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:14:35 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 10:31:40 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
	private:
	std::string _target;

	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& _copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& _copy);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
	void createTree() const;
};