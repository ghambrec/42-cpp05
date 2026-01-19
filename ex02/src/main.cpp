/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:41 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 22:48:40 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat ba("Jack", 1);
		Bureaucrat bb("Bob", 42);
		std::cout << ba;
		std::cout << bb;

		RobotomyRequestForm a("target");
		std::cout << a;
		// a.execute(bb);
		bb.signForm(a);
		bb.executeForm(a);


		
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << "\n";
	}
}
