/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:26:05 by miparis           #+#    #+#             */
/*   Updated: 2026/02/12 14:31:45 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Animal.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "Wrong Cat";
	std::cout << PURPLE << "(Def.) " << this->type << " ready to play!" << NC << std::endl;
}
WrongCat::WrongCat(std::string _type) : WrongAnimal(_type)
{
	/*if (std::string _type != "WrongCat" || &_type = NULL)
		this->type = "WrongCat";*/
	this->type = _type;
	std::cout << PURPLE << "(Assign) " << this->type << " ready to play!" << NC << std::endl;
}
WrongCat:: WrongCat(const WrongCat& _copy) : WrongAnimal(_copy)
{
	*this = _copy;
	std::cout << PURPLE << "(Copy) " << this->type << " ready to play!" << NC << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& _copy)
{
	if (this != &_copy)
		WrongAnimal::operator=(_copy);
	std::cout << PURPLE << "(Assign op.) " << this->type << " ready to play!" << NC << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "(Destruct.) " << this->type << " asleep!" << NC << std::endl;
}
void WrongCat::makeSound() const
{
	std::cout << BLUE << "Meeeee?" << std::endl;
}