/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:32:48 by miparis           #+#    #+#             */
/*   Updated: 2026/07/10 16:06:00 by miparis          ###   ########.fr       */
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

template <typename T>
void swap(T& firstArg, T& secondArg)
{
	T aux = firstArg;
	firstArg = secondArg;
	secondArg = aux;
}
template <typename T>
T min(T firstArg, T secondArg)
{
	if (firstArg < secondArg)
		return (firstArg);
	return (secondArg);
}
template <typename T>
T max(T firstArg,T secondArg)
{
	if (firstArg > secondArg)
		return (firstArg);
	return (secondArg);	
}