/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:09:47 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 20:07:26 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"

WrongAnimal:: WrongAnimal()
{
	this->type = "_random";
	std::cout << PURPLE << "(Def.) " << "WrongAnimal " << this->type << " ready to play!" << NC << std::endl;
}
WrongAnimal:: WrongAnimal(std::string _type)
{
	this->type = _type;
	std::cout << PURPLE << "(Assign) " << "WrongAnimal " << this->type << " ready to play!" << NC << std::endl;
}

WrongAnimal:: WrongAnimal(const WrongAnimal& _copy)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << "WrongAnimal " << this->type << " ready to play!" << NC << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& _copy)
{
	if (this != &_copy)
		this->type = _copy.type;
	std::cout << PURPLE << "(Assign op.) " << "WrongAnimal " << this->type << " ready to play!" << NC << std::endl;
	return (*this);
}

WrongAnimal:: ~WrongAnimal()
{
	std::cout << RED << "(Destruct.) " << "WrongAnimal " << this->type << " asleep!" << NC << std::endl;
}
	
void WrongAnimal::makeSound() const
{
	std::cout << YELLOW << this->type << " WrongAnimal tries to speak..." << NC << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}