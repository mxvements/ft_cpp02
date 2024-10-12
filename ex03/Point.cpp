/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:19:39 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/12 20:35:12 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):_coords{0,0,0}{}

Point::Point(int coords[3])
{
	this->setCoords(coords);
}

Point::~Point(void){}

void Point::setCoords(int coords[3])
{
	for (int i = 0; i < 3; i++)
	{
		this->_coords[i] = coords[i];
	}
}

int *Point::getCoords(void)
{
	return this->_coords;
}