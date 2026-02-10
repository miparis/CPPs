/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:23:36 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 18:47:45 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap:: ScavTrap() : ClapTrap()
{
	this->_name = "_default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << PURPLE << "(Default const.) " << "ScavTrap " << this->_name << " ready!" << NC << std::endl;
	status();
}

ScavTrap:: ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << PURPLE << "(Default const.)" << "ScavTrap " << this->_name << " ready!" << NC << std::endl;
	status();
}

ScavTrap::ScavTrap (const ScavTrap& _copy) : ClapTrap(_copy)
{
	std::cout << PURPLE << "(Copy const.) " << "ScavTrap " << this->_name << " ready!" << NC << std::endl;
	*this = _copy;
	status();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& _copy)
{
	if (this != &_copy)
		ClapTrap::operator=(_copy);
	std::cout << PURPLE << "(Copy assigment const.)" << "ScavTrap " << this->_name << " ready!" << NC << std::endl;
	status();
	return (*this);
}

ScavTrap:: ~ScavTrap(void)
{
	std::cout << PURPLE << "ScavTrap " << this->_name << ": GAME OVER" << NC << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BLUE << "ScavTrap " << this->_name << " attacks " << target << NC << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << YELLOW << "ScavTrap " << this->_name << " cant attack! No energy or hit points left!" << NC << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap " << this->_name << " is now in Gate keeper mode." << NC << std::endl;
}