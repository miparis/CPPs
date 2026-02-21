/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:23:42 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 14:19:57 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(const Cat& _copy);
	Cat& operator=(const Cat& _copy);
	~Cat();
	
	virtual void makeSound() const;
	void setIdeas(int i, const std::string& _newIdea);
	std::string getIdeas(int i) const;

	private:
	Brain*	brain;
};
