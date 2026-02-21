/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:43:29 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 11:49:35 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain(); //We allocate memory in the heap for a unique brain
	std::cout << PURPLE << "(Def.) " << this->type << " ready to play!" << NC << std::endl;
}

Dog:: Dog(const Dog& _copy) : Animal(_copy)
{
	this->brain = new Brain(*_copy.brain); //As the object to copy is new, we dont have to delete brain prior
	std::cout << PURPLE << "(Copy) " << this->type << " ready to play!" << NC << std::endl;
}
Dog& Dog::operator=(const Dog& _copy)
{
	if (this != &_copy)
	{
		Animal::operator=(_copy);
		if (this->brain)
			delete (this->brain); //We delete any remaining data to avoid leaks
		this->brain = new Brain(*_copy.brain);
	}
	std::cout << PURPLE << "(Assign op.) " << this->type << " ready to play!" << NC << std::endl;
	return (*this);
}

Dog:: ~Dog()
{
	delete (this->brain);//We ensure to delete the Brain to avoid leaks
	std::cout << RED << "(Destruct.) " << this->type << " asleep!" << NC << std::endl;
}
void Dog::makeSound() const
{
	std::cout << GREEN << "WOF WOF WOF" << std::endl;
}

void Dog::setIdeas(int i, const std::string& _newIdea)
{
	if (this->brain->ideas[i].empty())
		this->brain->ideas[i] = _newIdea;
}

std::string Dog::getIdeas(int i) const
{
	return (this->brain->ideas[i]);
}