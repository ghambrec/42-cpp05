/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:41 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 16:02:59 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat ba("Jack", 1);
		Bureaucrat bb("Bob", 150);
		std::cout << ba << "\n";
		std::cout << bb << "\n";
		AForm fa("GoodForm", 2, 20);
		AForm fb("BadForm", 142, 150);
		std::cout << fa << "\n";
		std::cout << fb << "\n";
		bb.signForm(fa);
		bb.signForm(fb);
		ba.signForm(fa);
		ba.signForm(fb);
		std::cout << fa << "\n";
		std::cout << fb << "\n";
		AForm fc("InvalidForm", 0, 150);
		std::cout << fc << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << "\n";
	}
}
