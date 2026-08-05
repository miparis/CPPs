/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:34:29 by miparis           #+#    #+#             */
/*   Updated: 2026/08/05 12:29:20 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : N(N)
{
	//if we don span(N) we would be filling the vector N times with 0s
	//hence we only reserve the space to use it later 
	_numbers.reserve(N);
}

Span::Span(){
}

Span::Span(const Span& _copy)
{
	*this = _copy;
}
Span& Span::operator=(const Span& _copy)
{
	if (this != &_copy)
		*this = _copy;
	return (*this);
}

Span:: ~Span(){}

void Span::addNumber(unsigned int _toadd)
{
	
	if (_numbers.size() >= N) 
		throw (std::exception()); 
	else
		_numbers.push_back(_toadd);
}

unsigned int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::exception();
	
	std::vector<int>	_sortedCopy = _numbers;
	std::sort(_sortedCopy.begin(), _sortedCopy.end());
	//sort is specific to containers

	//after sorting, we assume the shortest span 
	//is the difference between the two first values
	unsigned int	_mSpan = _sortedCopy[1] - _sortedCopy[0];

	for (size_t i = 0; i < _sortedCopy.size(); i++)
	{
		//we iterate annd search for a smaller difference
		unsigned int _cSpan = _sortedCopy[i] - _sortedCopy[i - 1];
		if (_cSpan < _mSpan)
			_mSpan = _cSpan;
	}
	return (_mSpan);
}
unsigned int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::exception();
	
	// We look for the min and max via std::min_element y std::max_element 
	// that return a pointer to these
	std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());

	// we dereference it to rest them and obtain the difference between those two 
	return (*max - *min);
}

