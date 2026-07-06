/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:11:42 by miparis           #+#    #+#             */
/*   Updated: 2026/07/06 12:54:17 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

/*
Here the function can change the array as its not const
*/
template <typename T>
void iter(T* reference, size_t lenght, void (*f)(T&))
{
	//(*f) = reference to function (T&) = array
	for (size_t i = 0; i < lenght; i++)
		f(reference[i]);
}
/*
Overload of the iter function that says "hey I am not going to change the reference to the array"
Here the function will be of reading only
*/
template <typename T>
void iter(const T* reference, size_t lenght, void (*f)(const T&))
{
	for (size_t i = 0; i < lenght; i++)
		f(reference[i]);
}