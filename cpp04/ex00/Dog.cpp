/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:43:29 by miparis           #+#    #+#             */
/*   Updated: 2026/02/12 21:51:56 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << PURPLE << "(Def.) " << this->type << " ready to play!" << NC << std::endl;
}
Dog::Dog(std::string _type) : Animal(_type)
{
	this->type = "Dog";
	std::cout << PURPLE << "(Assign) " << this->type << " ready to play!" << NC << std::endl;
}
Dog:: Dog(const Dog& _copy) : Animal(_copy)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << this->type << " ready to play!" << NC << std::endl;
}
Dog& Dog::operator=(const Dog& _copy)
{
	if (this != &_copy)
		Animal::operator=(_copy);
	if (this->type != "Dog")
            this->type = "Dog";
	std::cout << PURPLE << "(Assign op.) " << this->type << " ready to play!" << NC << std::endl;
	return (*this);
}

Dog:: ~Dog()
{
	std::cout << RED << "(Destruct.) " << this->type << " asleep!" << NC << std::endl;
}
void Dog::makeSound() const
{
	std::cout << GREEN << "WOF WOF WOF" << std::endl;
}