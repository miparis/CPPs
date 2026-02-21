/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:03:26 by miparis           #+#    #+#             */
/*   Updated: 2026/02/21 14:14:09 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	public:
	Brain();
	Brain(const Brain& _copy);
	Brain& operator=(const Brain& _copy);
	virtual ~Brain();
	
	std::string ideas[100];
};
