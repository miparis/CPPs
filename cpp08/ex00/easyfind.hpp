/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:45:46 by miparis           #+#    #+#             */
/*   Updated: 2026/07/15 13:20:45 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

template <typename T>
typename T::iterator easyfind(T& _container, int _int);
#include "easyfind.tpp"