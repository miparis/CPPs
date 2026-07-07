/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:01:00 by miparis           #+#    #+#             */
/*   Updated: 2026/07/07 16:21:31 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T> :: Array() : _size(0), _array(new T[0]()) 
{}

template <typename T>
Array<T>:: Array(unsigned int n) : _size(n), _array(new T[n]())
{}

template <typename T>
Array<T> :: Array(const Array& _copy) : _size(_copy._size)
{
	_array = new T[_size](); //We reserve the same amount of memory as the original

	for (unsigned int i = 0; i < _size; i++) //we copy one by one the
		_array[i] = _copy._array[i];
}

template <typename T>
Array<T>& Array<T> :: operator=(const Array<T>& _copy)
{
	if (this != &_copy)
	{
		delete[] _array;

		_size = _copy._size;
		_array = new T[_size]();

		for (unsigned int i = 0; i < _size; i++)
			_array[i] = _copy._array[i];
	}
	return (*this);
}

template <typename T>
Array<T> :: ~Array()
{
	delete[] _array;
}
template <typename T>
unsigned int Array<T> :: size() const
{
	return (_size);
}

template <typename T>
T& Array<T>:: operator[](unsigned int _index)
{
	if (_index >= _size) 
		throw (std::exception()); 
	return (_array[_index]);
}