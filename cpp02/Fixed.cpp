/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:04:38 by miparis           #+#    #+#             */
/*   Updated: 2025/11/16 17:40:24 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
	std::cout << GREEN << "Default constructor called" << NC << std::endl;
}

 // Copy constructor
Fixed::Fixed(const Fixed& _new)
{
	std::cout << BLUE << "Copy constructor called" << NC << std::endl;
	*this = _new;
}

 // Assigment operator overload
Fixed &Fixed::operator=(const Fixed& _new)
{
	std::cout << PURPLE << "Copy assignment operator called" << NC << std::endl;
	if (this != &_new ) //Auto asignation check, even if we dont have dinamic memory
	{
		//this->_fixed = _new._fixed;
		this->_fixed = _new.getRawBits();
	}
	return (*this);
}

Fixed:: ~Fixed(void)
{
	std::cout << RED << "Destructor called" << NC << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << YELLOW << "getRawBits member function called" << NC << std::endl;
	return (this->_fixed);
}
void Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}
