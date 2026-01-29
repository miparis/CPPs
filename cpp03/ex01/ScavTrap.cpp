/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:23:36 by miparis           #+#    #+#             */
/*   Updated: 2026/01/29 09:36:42 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << PURPLE << "ScavTrap " << this->_name << " ready!" << NC << std::endl;
	status();
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