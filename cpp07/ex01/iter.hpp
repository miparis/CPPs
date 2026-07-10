/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:11:42 by miparis           #+#    #+#             */
/*   Updated: 2026/07/10 17:20:27 by miparis          ###   ########.fr       */
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
Here the function passed can change the array as its not const
*/
template <typename T>
void iter(T* adress, const size_t length, void (*f)(T&))
{
	//(*f) = reference to function (T&) = array
	for (size_t i = 0; i < length; i++)
		f(adress[i]);
}
/*
Overload of the iter function that says "hey I am not going to change the array"
Here the function will be of reading only
*/
template <typename T>
void iter(const T* adress, const size_t length, void (*f)(const T&))
{
	for (size_t i = 0; i < length; i++)
		f(adress[i]);
}
/*------- The following function was made for testing a function template in iter -----*/
template <typename T>
void printElement(const T& element)
{
    std::cout << PURPLE << element << " " << NC << std::endl;;
}