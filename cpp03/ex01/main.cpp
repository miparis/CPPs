/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/01/29 09:38:00 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    // --- Instantiation and Constructor Chain ---
    // This confirms that the base class (ClapTrap) is built before the derived class (ScavTrap).
    // You should see both constructors in the output.
    ScavTrap _scav("Serebro");
    //scav.status(); 

    // --- Overridden Attack Method ---
    // Checks if ScavTrap uses its own attack message and correctly consumes energy.
    _scav.attack("an intruder");
    _scav.status(); 

    // --- Exclusive Special Ability ---
    // Verifies the unique guardGate() function that ClapTrap does not have.
    _scav.guardGate();

    // --- Durability and HP Thresholds ---
    // Confirms _scavTrap has 100 HP. A 15-damage hit would kill a ClapTrap, 
    // but a _scavTrap should remain standing.
    _scav.takeDamage(15);
    _scav.status(); 

    // --- Energy and Repair Logic ---
    // Ensures the repair function correctly adds HP and costs 1 EP.
    _scav.beRepaired(10);
    _scav.status(); 

    // --- Polymorphism and Virtual Destructor Verification ---
    // This is the most important technical test.
    // 1. It checks if a base pointer correctly calls the derived attack().
    // 2. It checks if 'delete' triggers BOTH destructors (_scav then Clap).
    ClapTrap* poly = new ScavTrap("PolyBot");
    poly->attack("Target Dummy"); 
    delete poly; 

    // --- Scope-based Destruction ---
    // When the function returns, the local '_scav' object is destroyed.
    return 0;
}