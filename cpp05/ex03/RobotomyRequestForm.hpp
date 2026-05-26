/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:02:28 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 11:21:10 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm 
{
	private:
	std::string _target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& _copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& _copy);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};