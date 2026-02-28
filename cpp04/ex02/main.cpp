/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:21:20 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 15:38:14 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main()
{
	// Animal _animal; -> When trying to just make an animal wew cant as it is abstract
	const Animal* j = new Dog(); //However, if we instanciate Animal with an specific type we force the inherence 
	const Animal* i = new Cat();
	
	std::cout << GREEN << "\n			--- Solicited test ---				\n" << NC << std::endl;
	const int size = 4;
	Animal* _animals[size];
	std::cout << BLUE << "Creating animals...\n" << NC << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			_animals[i] = new Dog();
		else
			_animals[i] = new Cat();
	}

	std::cout << GREEN << "\n			--- Deep copy test ---				\n" << NC << std::endl;
	Dog _dogy;
	_dogy.setIdeas(0, "wow a tought");
	_dogy.setIdeas(1, "wait... I am hungry!");
	_dogy.setIdeas(2, "I've been a good dogy! Should have a treat!");
	_dogy.setIdeas(3, "!");
	_dogy.setIdeas(4, "I love these bones!!!!");
	for (int i = 0; i < 5; i++)
		std::cout << BLUE << _dogy.getIdeas(i) << "\n" << NC << std::endl;


	delete j;//should not create a leak
	delete i;
	for (int x = 0; x < size; x++)
		delete _animals[x];
	return (0);
}