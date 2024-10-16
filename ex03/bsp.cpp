/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:36:26 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/16 20:10:54 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	*tr_area(Point *tr)
{
	Fixed factor(0.5f);
	Fixed v1_coords[2] = {tr[0].getCoords()[0], tr[0].getCoords()[1]};
	Fixed v2_coords[2] = {tr[1].getCoords()[0], tr[1].getCoords()[1]};
	Fixed v3_coords[2] = {tr[2].getCoords()[0], tr[2].getCoords()[1]};

	// std::cout << "\tv1: (" << v1_coords[0] << ", " << v1_coords[1] << ")" <<std::endl;
	// std::cout << "\tv2: (" << v2_coords[0] << ", " << v2_coords[1] << ")" <<std::endl;
	// std::cout << "\tv3: (" << v3_coords[0] << ", " << v3_coords[1] << ")" <<std::endl;

	// std::cout << "\t\tsum1: " << ((v2_coords[1] - v3_coords[1])) << std::endl;
	// std::cout << "\t\tsum1: " << ((v3_coords[1] - v1_coords[1])) << std::endl;
	// std::cout << "\t\tsum1: " << ((v1_coords[1] - v2_coords[1])) << std::endl;

	Fixed rslt_f = (factor * (
		(v1_coords[0] * (v2_coords[1] - v3_coords[1])) +
		(v2_coords[0] * (v3_coords[1] - v1_coords[1])) +
		(v3_coords[0] * (v1_coords[1] - v2_coords[1]))
	));

	if (rslt_f < 0)
		rslt_f = rslt_f * -1;
	Fixed *rslt = new Fixed(rslt_f);
	return (rslt);
}
Point *setTriangle(float coords1[2], float coords2[2], float coords3[2])
{
	Point *tr = new Point[3];
	tr[0].setCoords(coords1);
	tr[1].setCoords(coords2);
	tr[2].setCoords(coords3);
	return (tr);
}

/**
 * Evaluates whether a point is in a trinagle
 */
bool bsp(Point *tr, Point *p)
{
	Fixed *area_tr_base = tr_area(tr);
	if (area_tr_base->toFloat() == 0.0f)
	{
		std::cout << "Points do not form a triangle" << std::endl;
		return (0);
	}

	Point tr1[3] = {tr[0], tr[1], *p};
	Fixed *area_tr1 = tr_area(tr1);
	// std::cout << "Area tr1: "  << *area_tr1 << std::endl;
	
	Point tr2[3] = {tr[1], tr[2], *p};
	Fixed *area_tr2 = tr_area(tr2);
	// std::cout << "Area tr2: "  << *area_tr2 << std::endl;
	
	Point tr3[3] = {tr[2], tr[0], *p};
	Fixed *area_tr3 = tr_area(tr3);
	// std::cout << "Area tr3: "  << *area_tr3 << std::endl;

	std::cout << "SUM area: " << (*area_tr1 + *area_tr2 + *area_tr3) << std::endl;
	std::cout << "MAIN triangle area: " << *area_tr_base << std::endl;
	
	return ((*area_tr1 + *area_tr2 + *area_tr3) - *area_tr_base < 0.01f ? 1 : 0);
}