/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:26:05 by miparis           #+#    #+#             */
/*   Updated: 2026/02/12 21:52:13 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << PURPLE << "(Def.) " << this->type << " ready to play!" << NC << std::endl;
}
Cat::Cat(std::string _type) : Animal(_type)
{
	this->type = "Cat";
	std::cout << PURPLE << "(Assign) " << this->type << " ready to play!" << NC << std::endl;
}
Cat:: Cat(const Cat& _copy) : Animal(_copy)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << this->type << " ready to play!" << NC << std::endl;
}
Cat& Cat::operator=(const Cat& _copy)
{
	if (this != &_copy)
		Animal::operator=(_copy);
	if (this->type != "Cat")
            this->type = "Cat";
	std::cout << PURPLE << "(Assign op.) " << this->type << " ready to play!" << NC << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << RED << "(Destruct.) " << this->type << " asleep!" << NC << std::endl;
}
void Cat::makeSound() const
{
	std::cout << BLUE << "MIAU MIAU MIAU" << std::endl;
}