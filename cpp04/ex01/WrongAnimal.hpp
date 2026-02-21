/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:02:20 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 19:56:54 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_H
#define WrongAnimal_H

#include <iostream>

class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal(std::string _type);
	WrongAnimal(const WrongAnimal& _copy);
	WrongAnimal& operator=(const WrongAnimal& _copy);
	virtual ~WrongAnimal();
	
	virtual void makeSound() const;
	std::string getType() const;
	
	protected:
	std::string type;
};

#endif