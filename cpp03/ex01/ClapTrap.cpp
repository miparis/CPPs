/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:13 by miparis           #+#    #+#             */
/*   Updated: 2026/02/01 18:36:18 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap:: ClapTrap()
{
	this->_name = "_default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << PURPLE << "(Default const.) " << "ClapTrap " << this->_name << " ready!" << NC << std::endl;
	status();
}

ClapTrap::ClapTrap (std::string _name): _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << PURPLE << "(Default const.) " << "ClapTrap " << this->_name << " ready!" << NC << std::endl;
	status();
}

ClapTrap::ClapTrap (const ClapTrap& _copy)
{
	std::cout << PURPLE << "(Copy const.) " << "ClapTrap " << this->_name << " ready!" << NC << std::endl;
	*this = _copy;
	status();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& _copy)
{
	if (this != &_copy)
	{
		this->_name = _copy._name;
		this->_hitPoints = _copy._hitPoints;
		this->_energyPoints = _copy._energyPoints;
		this->_attackDamage = _copy._attackDamage;
	}
	std::cout << PURPLE << "(Copy assigment const) " << "ClapTrap " << this->_name << " ready!" << NC << std::endl;
	status();
	return (*this);
}

ClapTrap:: ~ClapTrap (void)
{
	std::cout << PURPLE << "ClapTrap " << this->_name << ": GAME OVER" << NC << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name << " attacks " << target << NC << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << YELLOW << "ClapTrap " << this->_name << " cant attack! No energy or hit points left!" << NC << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= amount)
	{
		std::cout << RED << "ClapTrap " << this->_name << " receives " << amount << " of damage!" << NC << std::endl;
		this->_hitPoints -= amount;
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->_name << " No hit points left to keep standing! Hit points = " << this->_hitPoints << NC << std::endl;
		this->_hitPoints = 0;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << GREEN << "ClapTrap " << this->_name << " repairs itself by " << amount << " points!" << NC << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << YELLOW << "ClapTrap " << this->_name << " has no energy points left to repair itself! To repair = " << amount << " Energy Points = " << _energyPoints << NC << std::endl;
}

void ClapTrap::status(void) const
{
    std::cout << "\n" << "--- [ STATUS: " << PURPLE << _name << NC << " ] ---" << std::endl;
    std::cout << "| " << GREEN  << "HP: " << _hitPoints << NC;
    std::cout << " | " << YELLOW << "EP: " << _energyPoints << NC;
    std::cout << " | " << RED    << "AD: " << _attackDamage << NC << " |" << std::endl;
    std::cout << "-----------------------" << "\n" << std::endl;
}