/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:12:58 by miparis           #+#    #+#             */
/*   Updated: 2026/08/19 12:01:20 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other){
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) 
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){
}


/*				Added  __iterators 				*/

template <typename T>
typename MutantStack<T>::_iterator MutantStack<T>::begin()
{
	return (this->c.begin());
	// 'c' is the container of std::stack where the data is saved
}

template <typename T>
typename MutantStack<T>::_iterator MutantStack<T>::end()
{
	return (this->c.end());
}