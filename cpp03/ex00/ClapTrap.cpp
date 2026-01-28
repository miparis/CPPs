/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:13 by miparis           #+#    #+#             */
/*   Updated: 2026/01/28 09:56:43 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap (std::string _name): _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << PURPLE << "ClapTrap" << this->_name << " ready!" << NC << std::endl;
	std::cout << GREEN << "Hit = " << this->_hitPoints << NC << std::endl;
	std::cout << YELLOW << "Energy = " << this->_energyPoints << NC << std::endl;
	std::cout << RED << "Damage = " << this->_attackDamage << NC << std::endl;
}

ClapTrap:: ~ClapTrap (void)
{
	std::cout << PURPLE << "ClapTrap" << this->_name << ": GAME OVER" << NC << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints >= 1)
	{
		std::cout << PURPLE << "ClapTrap" << this->_name << " attacks " << target << " causing 1 points of damage!" << NC << std::endl;
		this->_attackDamage++;
		this->_energyPoints--;
	}
	else
		std::cout << PURPLE << "ClapTrap" << this->_name << " No energy to attack left!" << NC << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints >= amount)
	{
		std::cout << PURPLE << "ClapTrap" << this->_name << " receives " << amount << " of damage!" << NC << std::endl;
		this->_hitPoints--;
	}
	else
		std::cout << PURPLE << "ClapTrap" << this->_name << " No hit points left!" << NC << std::endl;
	
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1)
	{
		std::cout << PURPLE << "ClapTrap" << this->_name << " repairs itself by " << amount << " points!" << NC << std::endl;
		this->_hitPoints--;
	}
	else
		std::cout << PURPLE << "ClapTrap" << this->_name << " No energy points left!" << NC << std::endl;
}

void ClapTrap::status(void) const {
    std::cout << "\n" << "--- [ STATUS: " << PURPLE << _name << NC << " ] ---" << std::endl;
    std::cout << "| " << GREEN  << "HP: " << _hitPoints << NC;
    std::cout << " | " << YELLOW << "EP: " << _energyPoints << NC;
    std::cout << " | " << RED    << "AD: " << _attackDamage << NC << " |" << std::endl;
    std::cout << "-----------------------" << "\n" << std::endl;
}