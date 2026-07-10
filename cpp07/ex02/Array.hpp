/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:54:39 by miparis           #+#    #+#             */
/*   Updated: 2026/07/10 17:23:22 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

template <typename T> class Array
{
	public:
	Array();
	Array(unsigned int n);
	Array(const Array& _copy);
	Array<T>& operator=(const Array<T>& _copy);
	~Array();
	
	unsigned int size() const;
	T& operator[](unsigned int _index);

	private:
	unsigned int	_size;
	T*				_array;
};

#include "Array.tpp"