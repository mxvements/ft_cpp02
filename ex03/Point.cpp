/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:19:39 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/17 20:51:55 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(float x, float y)
{
	this->setX(x);
	this->setY(y);
}

Point::~Point(void) {}

void Point::setX(Fixed x) { this->_x = x; }
void Point::setY(Fixed y) { this->_y = y; }
Fixed Point::getX(void) { return this->_x; }
Fixed Point::getY(void) { return this->_y; }

/**
 * copy constructor
 * Point b(a)
 * copy a in b
 * we are initializing b
 */
Point::Point(const Point &point)
{
	*this = point;
}

/**
 * Copy assignment
 * a = b
 * a,b both are initialized
 * this references a, sets a with the data from b
 */
Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		this->setX(point._x);
		this->setY(point._y);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, Point &p)
{
	Fixed x = p.getX();
	Fixed y = p.getY();

	os << "(" << x << ", " << y << ")";
	return (os);
}