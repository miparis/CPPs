/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:44:44 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 11:00:23 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << GREEN << "\n			--- Orthodox Canonical Form ---				\n" << NC << std::endl;
	std::cout << "--- Testing Default Constructor ---" << std::endl;
	Animal _animy;
	std::cout << _animy.getType() << " " << std::endl;

	std::cout << "\n--- Testing Parameterized Constructor ---" << std::endl;
	Animal _dogy("_dogy");
	std::cout << _dogy.getType() << " " << std::endl;

	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	Animal clone(_dogy);
	std::cout << _dogy.getType() << " " << std::endl;

	std::cout << "\n--- Testing Copy Assignment Operator ---" << std::endl;
	_animy = _dogy;
	std::cout << _animy.getType() << " " << std::endl;
	
	std::cout << GREEN << "\n			--- Test provided ---			\n" << NC << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	//	WrongCat test
	std::cout << GREEN << "\n			--- WrongAnimal Test ---			\n" << NC << std::endl;
	const WrongAnimal* x = new WrongCat();
	std::cout << x->getType() << " " << std::endl;
	x->makeSound(); //will output the wrong cat sound!
	
	//As we used the new operator to create the objects we have to delete them manually	
	std::cout << "\n" << std::endl;
	delete meta;
	delete i;
	delete j;
	delete x;
	
	return (0);
}