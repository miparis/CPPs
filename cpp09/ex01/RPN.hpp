/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:09:46 by miparis           #+#    #+#             */
/*   Updated: 2026/09/26 12:52:10 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <deque>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

class RPN
{
	public:
	RPN();
	RPN(const RPN &copy);
	RPN& operator=(const RPN &copy);
	~RPN();

	void RevertedPolishNotation(const std::string &_input);

	private:
	std::deque<int> _values;
	size_t _size;
};
