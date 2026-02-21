/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:42:28 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 14:14:33 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
	Dog();
	Dog(const Dog& _copy);
	Dog& operator=(const Dog& _copy);
	~Dog();
	
	virtual void makeSound() const;
	void setIdeas(int i, const std::string& _newIdea);
	std::string getIdeas(int i) const;

	private:
	Brain* brain; 
};
