/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:04:02 by miparis           #+#    #+#             */
/*   Updated: 2025/11/16 17:41:14 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

const std::string GREEN  = "\033[0;32m"; // Bold Green
const std::string YELLOW = "\033[0;33m"; // Yellow
const std::string RED    = "\033[0;31m"; // Red
const std::string BLUE   = "\033[0;34m"; // Bold Blue
const std::string PURPLE = "\033[0;35m"; // Bold Purple
const std::string BOLD   = "\033[1m";    // Bold text
const std::string NC     = "\033[0m";    // Reset color

class Fixed
{

	public:
	Fixed(void);
    Fixed(const Fixed& _new); // Copy constructor
    Fixed &operator=(const Fixed& e); // Assigment operator overload
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
	private:
	int _fixed;// An integer to store the fixed-point number value.
	const static int  _fractional = 8; //to store the number of fractional bits. Its value will always be the integer literal 8.Only 1 copy for this variable in the class, shared. Cannot be changed
};

#endif

