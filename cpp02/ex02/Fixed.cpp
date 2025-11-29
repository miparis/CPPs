/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:04:38 by miparis           #+#    #+#             */
/*   Updated: 2025/11/29 12:24:31 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0){
}

Fixed::Fixed(const Fixed& _new)
{
	*this = _new;
}

Fixed &Fixed::operator=(const Fixed& _new)
{
	if (this != &_new )
		this->_fixed = _new.getRawBits();
	return (*this);
}

Fixed:: ~Fixed(void){
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixed);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

Fixed::Fixed(const int _intNew) : _fixed(_intNew << _fractional){
}

Fixed::Fixed(const float _floatNew) : _fixed(roundf(_floatNew * (1 << _fractional))){
}

float Fixed::toFloat( void ) const
{
	float _rest;

	_rest = ((float)this->_fixed / (1 << _fractional));
	return (_rest);
}

int Fixed::toInt( void ) const
{
	return (this->_fixed >> _fractional);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
    return (os);
}

/*NEW CONSTRUCTORS AND FUNCTIONS*/

Fixed Fixed::operator+(const Fixed& _arg) const
{
	Fixed _result;

	_result.setRawBits(this->_fixed + _arg._fixed);
	return (_result);
}

Fixed Fixed::operator-(const Fixed& _arg) const
{
	Fixed _result;

	_result.setRawBits(this->_fixed - _arg._fixed);
	return (_result);
}

Fixed Fixed::operator*(const Fixed& _arg) const
{
	Fixed _result;
	long long _raw; //-> Helps to prevent overflow and store the result correctly

	_raw = (long long)this->_fixed * _arg._fixed;

    // The result is already correctly scaled by 2^8, so we set the raw bits.
    _result.setRawBits(_raw >> _fractional); // SHIFT RIGHT by 8 bits
	return (_result);
}

Fixed Fixed::operator/(const Fixed& _arg) const
{
	Fixed _result;
	long long _raw; //-> Helps to prevent overflow and store the result correctly

	_raw = (long long)this->_fixed << _fractional; //Moving the bits of the number to maintain the presition point

    // Scale the result back down by dividing by 2^8 (or shifting right by _fractional)
    _result.setRawBits(_raw / _arg._fixed); // SHIFT RIGHT by 8 bits
	return (_result);
}

bool Fixed::operator>(const Fixed& _arg) const
{
	return (this->_fixed > _arg._fixed);
}

bool Fixed::operator<(const Fixed& _arg) const
{
	return (this->_fixed < _arg._fixed);
}

bool Fixed::operator<=(const Fixed& _arg) const
{
	return (this->_fixed <= _arg._fixed);
}

bool Fixed::operator>=(const Fixed& _arg) const
{
	return (this->_fixed >= _arg._fixed);
}

bool Fixed::operator==(const Fixed& _arg) const
{
	return (this->_fixed == _arg._fixed);
}

bool Fixed::operator!=(const Fixed& _arg) const
{
	return (this->_fixed != _arg._fixed);
}

Fixed& Fixed::operator++()
{
	++this->_fixed;
	return (*this);
}

Fixed& Fixed::operator--()
{
	--this->_fixed;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed _temp(*this);
	
	this->_fixed -= 1;
	return (_temp);
}

Fixed Fixed::operator++(int)
{
	Fixed _temp(*this);

	this->_fixed += 1;
	return (_temp);
}

const Fixed& Fixed::min(Fixed& _a,  Fixed& _b)
{
	if (_a.getRawBits() < _b.getRawBits())
		return (_a);
	else
		return (_b);
}
const Fixed& Fixed::min(const Fixed& _a, const Fixed& _b)
{
	if (_a.getRawBits() < _b.getRawBits())
		return (_a);
	else
		return (_b);
}

const Fixed& Fixed::max(Fixed& _a,  Fixed& _b)
{
	if (_a.getRawBits() > _b.getRawBits())
		return (_a);
	else
		return (_b);
}
const Fixed& Fixed::max(const Fixed& _a, const Fixed& _b)
{
	if (_a.getRawBits() > _b.getRawBits())
		return (_a);
	else
		return (_b);
}