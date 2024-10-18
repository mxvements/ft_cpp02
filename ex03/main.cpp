/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:30:31 by luciama2          #+#    #+#             */
/*   Updated: 2024/10/18 18:41:44 by luciama2         ###   ########.fr       */
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
	Point a(1.2f, 3);
	Point b(2, 5.3f);
	Point c(3, 4.2f);
	std::cout << YELLOW << "EVAL Triangle: (" << a << ", " << b << ", " << c << ")" << RESET << std::endl;
	
	Point eval_pt1(2.5f, 4.1f);
	Point eval_pt2(2.2f, 2);
	
	//evaluate: is point in triangle?
	std::cout << YELLOW << "EVAL PT1: "<< eval_pt1 << RESET << std::endl;
	bsp(a, b, c, eval_pt1) 
		? (std::cout << GREEN << "Point in tringle" << RESET <<std::endl)
		: (std::cout << RED << "Point outside triangle" << RESET << std::endl);

	std::cout << YELLOW << "EVAL PT2: "<< eval_pt2 << RESET << std::endl;
	bsp(a, b, c, eval_pt2) 
		? (std::cout << GREEN << "Point in tringle" << RESET << std::endl)
		: (std::cout << RED << "Point outside triangle" << RESET << std::endl);
	return 0;
}