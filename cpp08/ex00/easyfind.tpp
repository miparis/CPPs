/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:51:52 by miparis           #+#    #+#             */
/*   Updated: 2026/07/15 13:19:48 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& _container, int _int)
{
	if (_container.empty())
		std::cerr << RED << "Error: Container empty" << NC << std::endl;
	typename T::iterator _it = find(_container.begin(),  _container.end(), _int);
	if (_it == _container.end())
        throw (std::exception());
	return (_it);
}
