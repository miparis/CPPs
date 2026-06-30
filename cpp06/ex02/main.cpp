/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:57:04 by miparis           #+#    #+#             */
/*   Updated: 2026/06/30 12:31:08 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << YELLOW << "--- TEST 1 ---" << NC << std::endl;
	Base* misteryObj1 = generate();

	std::cout << "Identify (pointer) = ";
	identify(misteryObj1);

	std::cout << "Identify (reference) = ";
	identify(*misteryObj1); // As we need to pass the real object by reference, we dereference the pointer using the * again

	delete (misteryObj1); // as we use new in genereta, we ensure to clean after

	std::cout << "\n--- TEST 2 ---" << std::endl;
	Base* misteryObj2 = generate();

	std::cout << "Identify (pointer) = ";
	identify(misteryObj2);

	std::cout << "Identify (refence) = ";
	identify(*misteryObj2);

	delete (misteryObj2);

	std::cout << "\n--- TEST 3 ---" << std::endl;
	Base* misteryObj3= generate();

	std::cout << "Identify (pointer) = ";
	identify(misteryObj3);

	std::cout << "Identify (refence) = ";
	identify(*misteryObj3);

	delete (misteryObj3);

	std::cout << "\n--- TEST 4 ---" << std::endl;
	Base* misteryObj4= generate();

	std::cout << "Identify (pointer) = ";
	identify(misteryObj4);

	std::cout << "Identify (refence) = ";
	identify(*misteryObj4);

	delete (misteryObj4);

	std::cout << "\n--- TEST 5 ---" << std::endl;
	Base* misteryObj5= generate();

	std::cout << "Identify (pointer) = ";
	identify(misteryObj5);

	std::cout << "Identify (refence) = ";
	identify(*misteryObj5);

	delete (misteryObj5);

	return (0);
}