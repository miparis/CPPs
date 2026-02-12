/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:23:42 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 19:57:08 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(std::string _type);
	Cat(const Cat& _copy);
	Cat& operator=(const Cat& _copy);
	~Cat();
	
	virtual void makeSound() const;
};

#endif