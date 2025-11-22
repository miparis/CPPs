/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:04:02 by miparis           #+#    #+#             */
/*   Updated: 2025/11/22 15:12:23 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

class Fixed
{

	public:
	Fixed(void);
    Fixed(const Fixed& _new);
    Fixed &operator=(const Fixed& e);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed(const int _intNew);
	Fixed(const float _floatNew);
	float toFloat( void ) const;
	int toInt( void ) const;
	/*Overload of operators*/
	Fixed Fixed::operator+(const Fixed& _arg) const;
	Fixed Fixed::operator-(const Fixed& _arg) const;
	Fixed Fixed::operator*(const Fixed& _arg) const;
	Fixed Fixed::operator/(const Fixed& _arg) const;

	bool Fixed::operator>(const Fixed& _arg) const;
	bool Fixed::operator<(const Fixed& _arg) const;
	bool Fixed::operator<=(const Fixed& _arg) const;
	bool Fixed::operator>=(const Fixed& _arg) const;
	bool Fixed::operator==(const Fixed& _arg) const;
	bool Fixed::operator!=(const Fixed& _arg) const;
	
	Fixed& Fixed::operator++();
	Fixed& Fixed::operator--();
	Fixed& Fixed::operator++(int); //Post increment
	Fixed& Fixed::operator--(int);  //Post decrement
	/*Overload functions*/

	
	private:
	int _fixed;
	const static int  _fractional = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

