/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:31 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/16 20:15:14 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/** 
 * program that determines whether a point is inside of a trinagle or not
 * 
 * cases to test;
 * 
 * tr = {
 * 	{1.2f, 2},
 * 	{2, 5.3f},
 * 	{3, 4.2f}	
 * }
 * 
 * pt = {2.2f, 2} -> outside triangle
 * pt = {2.5f, 4.1f} -> inside triangle
 */
int main(void)
{	
	float coords1[2] = {1.2f, 2};
	float coords2[2] = {2, 5.3f};
	float coords3[2] = {3, 4.2f};
	Point *tr = setTriangle(coords1, coords2, coords3);
	std::cout << "EVAL Triangle: (" << tr[0] << ", " << tr[1] << ", " << tr[2] << ")" << std::endl;
	
	float coords_eval1[2] = {2.5f, 4.1f};
	Point eval_pt1(coords_eval1);

	float coords_eval2[2] = {2.2f, 2};
	Point eval_pt2(coords_eval2);
	
	//evaluate: is point in triangle?
	std::cout << "EVAL PT1: "<< eval_pt1 << std::endl;
	bsp(tr, &eval_pt1) 
		? (std::cout << "Point in tringle" << std::endl)
		: (std::cout << "Point outside triangle" << std::endl);

	std::cout << "EVAL PT2: "<< eval_pt2 << std::endl;
	bsp(tr, &eval_pt2) 
		? (std::cout << "Point in tringle" << std::endl)
		: (std::cout << "Point outside triangle" << std::endl);
	return 0;
}