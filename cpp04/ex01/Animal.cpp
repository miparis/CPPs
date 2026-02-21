/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:09:47 by miparis           #+#    #+#             */
/*   Updated: 2026/02/12 23:10:17 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal:: Animal()
{
	this->type = "_random";
	std::cout << PURPLE << "(Def.) " << "Animal " << this->type << " ready to play!" << NC << std::endl;
}
Animal:: Animal(std::string _type)
{
	this->type = _type;
	std::cout << PURPLE << "(Assign) " << "Animal " << this->type << " ready to play!" << NC << std::endl;
}

Animal:: Animal(const Animal& _copy)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << "Animal " << this->type << " ready to play!" << NC << std::endl;

}
Animal& Animal::operator=(const Animal& _copy)
{
	if (this != &_copy)
		this->type = _copy.type;
	std::cout << PURPLE << "(Assign op.) " << "Animal " << this->type << " ready to play!" << NC << std::endl;
	return (*this);
}

Animal:: ~Animal()
{
	std::cout << RED << "(Destruct.) " << "Animal " << this->type << " asleep!" << NC << std::endl;
}
	
void Animal::makeSound() const
{
	std::cout << YELLOW << this->type << " animal tries to speak..." << NC << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}