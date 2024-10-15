/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:36:26 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/15 22:25:42 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	*tr_area(Point *tr)
{
	float v1_coords[2] = {tr[0].getCoords()[0].toFloat(), tr[0].getCoords()[1].toFloat()};
	float v2_coords[2] = {tr[1].getCoords()[0].toFloat(), tr[1].getCoords()[1].toFloat()};
	float v3_coords[2] = {tr[2].getCoords()[0].toFloat(), tr[2].getCoords()[1].toFloat()};

	std::cout << "v1: " << v1_coords[0] << ", " << v1_coords[1] << std::endl;
	std::cout << "v2: " << v2_coords[0] << ", " << v2_coords[1] << std::endl;
	std::cout << "v3: " << v3_coords[0] << ", " << v3_coords[1] << std::endl;
	
	float rslt_f = (float)(0.5 * (
		(float)(v1_coords[0] * (v2_coords[1] - v3_coords[1])) + 
		(float)(v2_coords[0] * (v3_coords[1] - v1_coords[1])) + 
		(float)(v3_coords[0] * (v1_coords[1] - v2_coords[1]))
	));
	std::cout << "rslt: " << rslt_f << std::endl;

	if (rslt_f == 0)
		std::cout << "Point do not form a triangle" << std::endl;
	if (rslt_f < 0)
		rslt_f *= -1;
	Fixed *rslt = new Fixed(rslt_f);
	return (rslt);
}

/**
 * Evaluates whether a point is in a trinagle
 */
bool bsp(Point *tr, Point *p)
{
	// (void)tr;
	(void)p;
	Point v1 = tr[0];
	Point v2 = tr[2];
	Point v3 = tr[3];

	Fixed *area_tr = tr_area(tr);
	std::cout << "are of main triangle: " << *area_tr << std::endl;

	return (0);
}