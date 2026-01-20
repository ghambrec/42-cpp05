/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:41 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/20 08:36:45 by ghambrec         ###   ########.fr       */
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
		Bureaucrat bb("Bob", 147);
		std::cout << ba;
		std::cout << bb;

		// try to execute a non signed form
		std::cout << "### try to execute a non signed form ###\n";
		ShrubberyCreationForm shrub("somewhere");
		std::cout << shrub;
		ba.executeForm(shrub);
		// try to sign form with lower grade
		std::cout << "### try to sign form with lower grade ###\n";
		bb.signForm(shrub);
		// sign the form
		std::cout << "### sign the form ###\n";
		ba.signForm(shrub);
		// try to execute a signed form with lower grade
		std::cout << "### try to execute a signed form with lower grade ###\n";
		bb.executeForm(shrub);
		// execute the form
		std::cout << "### execute the form ###\n";
		ba.executeForm(shrub);

		// tests for presidential and robotomy form
		std::cout << "### tests for presidential and robotomy form ###\n";
		RobotomyRequestForm robo("Worker");
		PresidentialPardonForm presi("Somewho");
		std::cout << robo;
		std::cout << presi;
		ba.signForm(robo);
		ba.signForm(presi);
		ba.executeForm(robo);
		ba.executeForm(robo);
		ba.executeForm(robo);
		ba.executeForm(robo);
		ba.executeForm(robo);
		ba.executeForm(presi);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << "\n";
	}
}
