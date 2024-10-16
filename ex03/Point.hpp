/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:19:37 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/16 19:31:18 by luciama2         ###   ########.fr       */
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
		Fixed _coords[2];
	
	public:
		Point(void);
		Point(float coords[2]);
		~Point(void);
		void setCoords(float coords[2]);
		Fixed *getCoords(void);
		friend std::ostream &operator<<(std::ostream &os, Point &p);
} ;

Point *setTriangle(float coords1[2], float coords2[2], float coords3[2]);
bool bsp(Point *tr, Point *p);

#endif