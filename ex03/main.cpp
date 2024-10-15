/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:31 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/15 22:25:23 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/** 
 * program that determines whether a point is inside of a trinagle or not
 */
int main(void)
{	
	float coords1[2] = {1.2f, 2};
	float coords2[2] = {2, 5.3f};
	float coords3[2] = {3, 4.2f};
	
	Point triangle[3];
	triangle[0].setCoords(coords1);
	triangle[1].setCoords(coords2);
	triangle[2].setCoords(coords3);
	
	float coords_eval[2] = {2.2f, 2};
	Point eval_pt(coords_eval);
	
	//print values to check
	std::cout << "trinagle: v1: " << triangle[0]
		<< ", v2: " << triangle[1]
		<< ", v3: " << triangle[2] << std::endl;
	std::cout << "pt to evaluate: "<< eval_pt << std::endl;
	
	//evaluate: is point in triangle?
	bsp(triangle, &eval_pt);
	return 0;
}