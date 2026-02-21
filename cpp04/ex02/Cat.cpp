/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:26:05 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 11:52:47 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << PURPLE << "(Def.) " << this->type << " ready to play!" << NC << std::endl;
}

Cat:: Cat(const Cat& _copy) : Animal(_copy)
{
	this->brain = new Brain(*_copy.brain);
	std::cout << PURPLE << "(Copy) " << this->type << " ready to play!" << NC << std::endl;
}
Cat& Cat::operator=(const Cat& _copy)
{
	if (this != &_copy)
	{
		Animal::operator=(_copy);
		if (this->brain)
			delete (this->brain);
		this->brain = new Brain(*_copy.brain);
	}
	std::cout << PURPLE << "(Assign op.) " << this->type << " ready to play!" << NC << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << RED << "(Destruct.) " << this->type << " asleep!" << NC << std::endl;
}
void Cat::makeSound() const
{
	std::cout << BLUE << "MIAU MIAU MIAU" << std::endl;
}

void Cat::setIdeas(int i, const std::string& _newIdea)
{
	if (this->brain->ideas[i].empty())
		this->brain->ideas[i] = _newIdea;
}

std::string Cat::getIdeas(int i) const
{
	return (this->brain->ideas[i]);
}