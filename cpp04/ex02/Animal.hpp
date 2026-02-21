/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:02:20 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 13:01:55 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

class Animal
{
	public:
	Animal();
	Animal(const Animal& _copy);
	Animal& operator=(const Animal& _copy);
	Animal(std::string _type);
	virtual ~Animal();
	
	virtual void makeSound() const = 0;
	 //This is what makes ANimal purely abstract, there is no "definition" publicly available of makeSound
	std::string getType() const;
	
	protected:
	std::string type;
};

#endif