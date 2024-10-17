/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:19:37 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/17 20:50:55 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;
	
	public:
		Point(void);
		Point (float x, float y);
		~Point(void);
		Point(const Point &point); //copy constructor
		Point &operator=(const Point &point); //copy assignment
		//getters, setters
		void setX(Fixed x);
		void setY(Fixed y);
		Fixed getX(void);
		Fixed getY(void);
		//operators overload
		friend std::ostream &operator<<(std::ostream &os, Point &p);
} ;

Point *setTriangle(float coords1[2], float coords2[2], float coords3[2]);
bool bsp(Point *tr, Point *p);

#endif