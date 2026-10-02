/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 17:53:52 by miparis           #+#    #+#             */
/*   Updated: 2026/10/02 11:15:33 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	if (this != &copy)
		*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->_vector = copy._vector;
		this->_list = copy._list;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

/*=============== INPUT VALIDATIONS & CHARGE ======================*/

bool PmergeMe::isValidNumber(const std::string &_input) const
{
	if (_input.empty()) 
		return (false);

	for (size_t i = 0; i < _input.length(); ++i)
	{
		if (!isdigit(_input[i]))
			return (false);
	}

	long _value = std::atol(_input.c_str());
	if (_value < 0 || _value > INT_MAX)
		return (false);

	return (true);
}

bool PmergeMe::validateArgs(int argc, char **argv) const
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (!isValidNumber(arg))
        {
            std::cerr << RED << "Error" << NC << std::endl;
            return (false);
        }
    }
    return (true);
}

/*==================== PRINTING ====================*/

void PmergeMe::printSequence() const
{
	std::vector<int>::const_iterator it;
	for (it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/* ============= TEMPLATES FORD-JHONSON =================*/

template <typename container, typename pairContainer>
void PmergeMe::separatePairs(container& _container, pairContainer& _pair, int& _horfan, bool &hasHorfan)
{
	//we check if the containers have impares
	hasHorfan = (_container.size() % 2 != 0);

	// universal iterator compatible with vector and list
	typename container::iterator it = _container.begin();

	// we go through the containers in two parts
	size_t pairs_count = _container.size() / 2;

	for (size_t i = 0; i < pairs_count; ++i)
	{
		//we do a first iteration
		int first_val = *it;
		++it;
		int second_val = *it;
		++it;
		
		//we pair ensuring the biggest nmb is the FIRST & the lowest the SECOND (Main chain)
		if (first_val > second_val)
			_pair.push_back(std::make_pair(first_val, second_val));
		else
			_pair.push_back(std::make_pair(second_val, first_val));
	}

	// if we have one left, its the horfan
	if (hasHorfan)
		_horfan = *it;
}
	
template <typename pairContainer>
void PmergeMe::orderPairs(pairContainer &_pair)
{
	//if we have an horfan we return
	if (_pair.size() <= 1)
		return ;

	//we will separate the pairs container in two halfs
	pairContainer _left;
	pairContainer _right;

	size_t half = _pair.size()/ 2;
	typename pairContainer::iterator it = _pair.begin();

	//we separate the pairs in the two halfs
	for (size_t i = 0; i < half; ++i)
	{
		_left.push_back(*it);
		++it;
	}
	while (it != _pair.end())
	{
		_right.push_back(*it);
		++it;
	}
	//we use this method again to order inside
	orderPairs(_left);
	orderPairs(_right);

	//here comes the merge to put both halfs into the original container

	_pair.clear(); //we clear the original container to avoid double comparisons

	//we create new iterators to use in the orig container
	typename pairContainer::iterator _it_left = _left.begin();
	typename pairContainer::iterator _it_right = _right.begin();

	//we start ordering using the biggest pair nmb
	// we check our iterators to avoid going out of limit
	while (_it_left != _left.end() && _it_right != _right.end())
	{
		if (_it_left->first < _it_right->first)
		{
			_pair.push_back(*_it_left);
			++_it_left;
		}
		else
		{
			_pair.push_back(*_it_right);
			++_it_right;
		}
	}

	// hanging numbers to the left
    while (_it_left != _left.end())
    {
        _pair.push_back(*_it_left);
        ++_it_left;
    }
    //  hanging numbers to the right
    while (_it_right != _right.end())
    {
        _pair.push_back(*_it_right);
        ++_it_right;
    }
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int size)
{
	//we create two containes to save the nmbrs and results of the sequence
	std::vector<int> jacobsthal;
	std::vector<int> sequence;

	// Every Jacob secuence starts with adding 0 and 1  as base cases
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	//iteradorators for checking pending nbrs
	int last_jacob = 1;
	int curr_jacob = 1;

	// Generate the  Jacobsthal numbers until we have the size of our pendings
	while (curr_jacob < size)
	{
		//J_n = J_{n-1} + 2J_{n-2}
		//this allows us to have the numbers as indexes for the search
		curr_jacob = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(curr_jacob);
	}

	// We create the sequence with thos indexes aka trampolins
	last_jacob = 1;
	//we start always with the 3rd position
	for (size_t i = 3; i < jacobsthal.size(); ++i)
	{
		curr_jacob = jacobsthal[i];
		
		// if the number in the Jacobsthal is bigger than the amout of elements,
		// we use it as a limit
		int start = curr_jacob;
		if (curr_jacob > size)
			start = size;
		
		// As we have the biggest, we start adding from the last one and onwards
		for (int j = start; j > last_jacob; --j)
			sequence.push_back(j);
		last_jacob = curr_jacob;
	}

	return (sequence);
}
template <typename container, typename pairContainer>
void PmergeMe::performFordJhonson(container &_container, pairContainer &_pairs, int _horfan, bool &hasHorfan)
{
	_container.clear();

    // Special case: only 1 nmb, a horfan
    if (_pairs.empty())
    {
        if (hasHorfan)
            _container.push_back(_horfan);
        return;
    }

    // We clean to create the Main Chain and an aux container
    container _pending;

    // 2. We split the pairs that are ordered:
    // - The biggest ones (.first) go directly to the Main Chain
    // - The smallest ones (.second) wait in _pending
	// This ensures that the nmbs in the main chain are already in order
    typename pairContainer::iterator it_pairs = _pairs.begin();
    while (it_pairs != _pairs.end())
    {
        _container.push_back(it_pairs->first);
        _pending.push_back(it_pairs->second);
        ++it_pairs;
    }

    // 3. In Ford-Johnson, the first element of pending is always the smallest element of the main chain
	// so we dont compare it and just put it at the front
    _container.insert(_container.begin(), _pending.front());

    // 4. We generate and save the Jacobsthal sequence to have the indexes to start ordering
    std::vector<int> _jacobSeq = generateJacobsthalSequence(_pending.size());

    // 5.We start inserting following the Jacobsthal Sequence
    for (size_t i = 0; i < _jacobSeq.size(); ++i)
    {
        // Jacobsthal goes from 1, containers start at 0
        int target_index = _jacobSeq[i] - 1;

        // std::list uses std::advanc to change positions without changing it
        typename container::iterator it_pend = _pending.begin();
        std::advance(it_pend, target_index);
		// std::list uses std::advanc to change positions without changing it
		// with std::vector we use []
        int value_to_insert = *it_pend;

		//we search for the index of that number with lower_bound
		// Finds the first position in which val could be inserted without changing the ordering.
		// Returns an iterator pointing to the first elementnot less than val, or end() if every element is less than val.
        typename container::iterator insert_pos = std::lower_bound(_container.begin(), _container.end(), value_to_insert);

        //and insert it there
        _container.insert(insert_pos, value_to_insert);
    }

    // 6. If we have an horfan, we look for its position and end
    if (hasHorfan)
    {
        typename container::iterator insert_pos = std::lower_bound(_container.begin(), _container.end(), _horfan);
        _container.insert(insert_pos, _horfan);
    }
}


void PmergeMe::executeSorts(int argc, char **argv)
{
	std::cout  << BOLD  << BLUE << "Before: " << NC;
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

	// ====================== STD::VECTOR ====================================
	std::clock_t start_vec = std::clock(); //we start the time

	// innit vector
	for (int i = 1; i < argc; ++i)
	{
		this->_vector.push_back(std::atoi(argv[i]));
	}

	//here we create the container with the inputed values
	std::vector< std::pair<int, int> > vec_pairs;
	int vec_horfan = 0;
	bool vec_hasHorfan = false;

	// we separate by pairs, order them and perfom the Ford Jhonson
	this->separatePairs(this->_vector, vec_pairs, vec_horfan, vec_hasHorfan);
	this->orderPairs(vec_pairs);
	this->performFordJhonson(this->_vector, vec_pairs, vec_horfan, vec_hasHorfan);

	std::clock_t end_vec = std::clock(); // we stop time and save it
	//convert the seconds in microseconds(us)
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;

	// ======================   STD::LIST ============================
	std::clock_t start_list = std::clock();

	//innit list
	for (int i = 1; i < argc; ++i)
	{
		this->_list.push_back(std::atoi(argv[i]));
	}

	std::list< std::pair<int, int> > list_pairs;
	int list_horfan = 0;
	bool list_hasHorfan = false;

	this->separatePairs(this->_list, list_pairs, list_horfan, list_hasHorfan);
	this->orderPairs(list_pairs);
	this->performFordJhonson(this->_list, list_pairs, list_horfan, list_hasHorfan);

	std::clock_t end_list = std::clock();
	double time_list = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC * 1000000.0;

	// ===========================  Results  ===================================
	std::cout << BOLD << PURPLE << "After:  " << NC;
	this->printSequence();

	// printing time difference as the subject
	std::cout << "Time to process a range of " << this->_vector.size() 
				<< " elements with std::vector : " << time_vec << " us" << std::endl;
				
	std::cout << "Time to process a range of " << this->_list.size() 
				<< " elements with std::list   : " << time_list << " us" << std::endl;
}