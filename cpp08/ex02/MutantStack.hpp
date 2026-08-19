/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:04:03 by miparis           #+#    #+#             */
/*   Updated: 2026/08/19 11:57:31 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <iterator>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

template <typename T> 
class MutantStack : public std::stack <T> 
{
	public:
	MutantStack();
	MutantStack(const MutantStack& _copy);
	MutantStack& operator=(const MutantStack& _copy);
	~MutantStack();
	
	// As a stack doesnt have iterators, 
	//Container_type: represent the container type used at compilation
	// (deque, list, vector,etc) and returns its iterator.
	//This allowes us to use the class with different types of containers
	typedef typename std::stack<T>::container_type::iterator _iterator;
	
	_iterator begin();
	_iterator end();
};

#include "MutantStack.tpp"