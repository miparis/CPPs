/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:17:19 by miparis           #+#    #+#             */
/*   Updated: 2026/01/28 09:57:34 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*int main(void)
{
	ClapTrap _mario("_Mario");
	ClapTrap _warrio("_Warrio");

	std::cout << GREEN <<  "Battle begins!" << NC << std::endl;
	_mario.attack("_Warrio");
	_warrio.takeDamage(5);
	_warrio.beRepaired(2);
	_warrio.attack("_Mario");
	_mario.takeDamage(4);
}*/
int main() {
    std::cout << "--- TEST 1: Creación ---" << std::endl;
    ClapTrap mario("Mario");
    ClapTrap warrio("Warrio");
    mario.status();
    warrio.status();

    std::cout << "--- TEST 2: Agotar Energía ---" << std::endl;
    // Mario tiene 10 EP. Atacamos 10 veces.
    for (int i = 0; i < 10; i++) {
        mario.attack("un Goomba");
    }
    mario.status(); // Aquí verás EP en 0

    std::cout << "--- TEST 3 y 4: Intentos fallidos ---" << std::endl;
    mario.attack("un Goomba"); // No debería gastar nada ni hacer nada
    mario.beRepaired(5);       // No debería curar nada
    mario.status();            // Los valores deberían seguir igual (EP 0, HP 10)

    std::cout << "--- TEST 5: Muerte por daño ---" << std::endl;
    warrio.status();           // Estado inicial de Warrio
    warrio.takeDamage(10);     // Recibe daño letal
    warrio.status();           // Verás HP en 0

    std::cout << "--- TEST 6: Acciones post-mortem ---" << std::endl;
    warrio.attack("Mario");
    warrio.beRepaired(10);
    warrio.status();           // Los valores no deben cambiar (HP sigue en 0)

    return 0;
}