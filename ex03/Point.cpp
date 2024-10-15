/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:19:39 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/15 22:20:41 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point(void)
{
	for (int i = 0; i < 2; i++)
	{
		this->_coords[i] = 0;
	}
}

Point::Point(float coords[2])
{
	this->setCoords(coords);
}

Point::~Point(void){}

void Point::setCoords(float coords[2])
{
   this->_coords[0] = Fixed(coords[0]);
    this->_coords[1] = Fixed(coords[1]);
}

Fixed *Point::getCoords(void)
{
	return this->_coords;
}

std::ostream &operator<<(std::ostream &os, Point &p)
{
	Fixed *coords = p.getCoords();
	
	os << "(";
	for(int i = 0; i < 2; i++)
	{
		os << coords[i];
		if (i != 1)
			os << ", ";
	}
	os << ")";
	return (os);
}