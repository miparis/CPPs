/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:16 by miparis           #+#    #+#             */
/*   Updated: 2026/02/01 18:00:42 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

class ClapTrap
{

	public:
	ClapTrap();
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& _copy);
	ClapTrap& operator=(const ClapTrap& _copy);
	virtual ~ClapTrap(void);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void status(void) const;

	protected:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;
};

#endif