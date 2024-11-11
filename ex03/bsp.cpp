/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:36:26 by luciama2          #+#    #+#             */
/*   Updated: 2024/11/11 21:46:03 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed *tr_area(Point *tr)
{
	Fixed factor(0.5f);
	Fixed v1_coords[2] = {tr[0].getX(), tr[0].getY()};
	Fixed v2_coords[2] = {tr[1].getX(), tr[1].getY()};
	Fixed v3_coords[2] = {tr[2].getX(), tr[2].getY()};

	Fixed rslt_f = (factor * ((v1_coords[0] * (v2_coords[1] - v3_coords[1])) +
							  (v2_coords[0] * (v3_coords[1] - v1_coords[1])) +
							  (v3_coords[0] * (v1_coords[1] - v2_coords[1]))));

	if (rslt_f < 0)
		rslt_f = rslt_f * -1;
	Fixed *rslt = new Fixed(rslt_f);
	return (rslt);
}

/**
 * OK
 * control if point is in line
 * control if main triangle area is 0
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point main_tr[3] = {a, b, c};
	Fixed *main_tr_area = tr_area(main_tr);

	if (main_tr_area->toFloat() <= 0.001f)
	{
		std::cerr << RED << "Main triangle ABC is a line" << RESET << std::endl;
		return (0);
	}

	Point tr1[3] = {a, b, point};
	Fixed *area_tr1 = tr_area(tr1);
	if (area_tr1->toFloat() <= 0.001f)
	{
		std::cout << ORANGE << "Point in AB line" << RESET << std::endl;
	}

	Point tr2[3] = {b, c, point};
	Fixed *area_tr2 = tr_area(tr2);
	if (area_tr2->toFloat() <= 0.001f)
	{
		std::cout << ORANGE << "Point in BC line" << RESET << std::endl;
	}

	Point tr3[3] = {c, a, point};
	Fixed *area_tr3 = tr_area(tr3);
	if (area_tr3->toFloat() <= 0.001f)
	{
		std::cout << ORANGE << "Point in CA line" << RESET << std::endl;
	}

	std::cout << "\tSUM area: " << (*area_tr1 + *area_tr2 + *area_tr3) << std::endl;
	std::cout << "\tMAIN triangle area: " << *main_tr_area << std::endl;

	return ((*area_tr1 + *area_tr2 + *area_tr3) - *main_tr_area < 0.01f ? 1 : 0);
}
