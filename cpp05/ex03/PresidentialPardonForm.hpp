/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:27:23 by miparis           #+#    #+#             */
/*   Updated: 2026/05/26 11:27:54 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once 

#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
	private:
	std::string _target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& _copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& _copy);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};