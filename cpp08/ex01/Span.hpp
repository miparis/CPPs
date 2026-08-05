/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:25:01 by miparis           #+#    #+#             */
/*   Updated: 2026/08/05 12:31:47 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

class Span
{
	private:
	std::vector<int>	_numbers;
	unsigned int		N;
	Span();

	public:
	Span(unsigned int N);
	Span(const Span& _copy);
	Span& operator=(const Span& _copy);
	~Span();

		
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addNumber(unsigned int _toadd);
	template <typename inputIt>
	void addNumbers(inputIt begin, inputIt end)
	{
		size_t _dis = std::distance(begin, end);// Save how many numbers we eant to save

		if (_dis > (N - _numbers.size()))
			throw std::exception(); // If there is not enough space to fill

		_numbers.insert(_numbers.end(), begin, end);
		//we just insert the numbers at the end, as it was a for loop
	}
};
