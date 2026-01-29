/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:13 by miparis           #+#    #+#             */
/*   Updated: 2026/01/29 09:36:15 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap (std::string _name): _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << PURPLE << "ClapTrap " << this->_name << " ready!" << NC << std::endl;
	std::cout << GREEN << "Hit = " << this->_hitPoints << NC << std::endl;
	std::cout << YELLOW << "Energy = " << this->_energyPoints << NC << std::endl;
	std::cout << RED << "Damage = " << this->_attackDamage << NC << std::endl;
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
		std::cout << YELLOW << "ClapTrap " << this->_name << " No hit points left to keep standing! Hit points = " << this->_hitPoints << NC << std::endl;
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