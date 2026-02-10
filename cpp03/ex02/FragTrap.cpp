/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:06:45 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 18:52:26 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap:: FragTrap() : ClapTrap()
{
	this->_name = "_default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << PURPLE << "(Default const.) " << "FragTrap " << this->_name << " ready!" << NC << std::endl;
	status();
}

FragTrap:: FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << PURPLE << "(Default const.)" << "FragTrap " << this->_name << " ready!" << NC << std::endl;
	status();
}

FragTrap:: FragTrap(const FragTrap& _copy) :ClapTrap(_copy)
{
	std::cout << PURPLE << "(Copy const.) " << "FragTrap " << this->_name << " ready!" << NC << std::endl;
	*this = _copy;
	status();
}
FragTrap& FragTrap::operator=(const FragTrap& _copy)
{
	if (this != &_copy)
		ClapTrap::operator=(_copy);
	std::cout << PURPLE << "(Copy assigment const.)" << "FragTrap " << this->_name << " ready!" << NC << std::endl;
	status();
	return (*this);
}

FragTrap:: ~FragTrap(void)
{
	std::cout << PURPLE << "FragTrap " << this->_name << ": GAME OVER" << NC << std::endl;
}

void FragTrap:: highFivesGuys()
{
	std::cout << RED << "FragTrap " << this->_name << " high fives you!!" << std::endl;
}

/*void FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BLUE << "FragTrap " << this->_name << " attacks " << target << NC << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << YELLOW << "FragTrap " << this->_name << " cant attack! No energy or hit points left!" << NC << std::endl;
}*/