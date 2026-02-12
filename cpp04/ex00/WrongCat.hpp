/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:23:42 by miparis           #+#    #+#             */
/*   Updated: 2026/02/10 19:57:08 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_H
#define WrongCat_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	WrongCat(std::string _type);
	WrongCat(const WrongCat& _copy);
	WrongCat& operator=(const WrongCat& _copy);
	~WrongCat();
	
	virtual void makeSound() const;
};

#endif