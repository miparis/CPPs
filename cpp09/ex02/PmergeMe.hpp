/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:46:12 by miparis           #+#    #+#             */
/*   Updated: 2026/10/02 11:16:06 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include <climits>
#include <utility>   // Para std::pair
#include <iterator>  // Para std::advance y std::distance
#include <ctime> // std::clock() for time 
#include <algorithm>
#include <vector>
#include <list>

const std::string GREEN  = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string RED    = "\033[0;31m";
const std::string BLUE   = "\033[0;34m";
const std::string PURPLE = "\033[0;35m";
const std::string BOLD   = "\033[1m";
const std::string NC     = "\033[0m";

class PmergeMe
{
	public:
	PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe& operator=(const PmergeMe &copy);
    ~PmergeMe();

	void executeSorts(int argc, char **argv);
	bool validateArgs(int argc, char **argv) const;

	private:
	std::vector<int> _vector;
    std::list<int>   _list;

	bool isValidNumber(const std::string &_input) const;
	void printSequence() const;

	// Templates for sorting
	template <typename container, typename pairContainer>
	void separatePairs(container& _container, pairContainer& _pair, int& _horfan, bool &hasHorfan);
	
	template <typename pairContainer>
	void orderPairs(pairContainer &_pair);

	std::vector<int> generateJacobsthalSequence(int size);
	template <typename container, typename pairContainer>
	void performFordJhonson(container &_container, pairContainer &_pairs, int _horfan, bool &hasHorfan);
};