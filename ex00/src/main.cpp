/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:41 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/15 11:01:35 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("bob", 1);
		std::cout << a << "\n";
		// a.incrementGrade();
		a.decrementGrade();
		std::cout << a << "\n";
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Caught GradeTooHighException: " << e.what() << "\n";
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Caught GradeTooLowException: " << e.what() << "\n";
	}
}
