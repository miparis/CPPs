/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:23:42 by miparis           #+#    #+#             */
/*   Updated: 2026/02/12 22:32:13 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(const Cat& _copy);
	Cat& operator=(const Cat& _copy);
	~Cat();
	
	virtual void makeSound() const;
};

#endif