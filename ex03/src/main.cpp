/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:41 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/20 13:29:07 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat ba("Jack", 1);
		Bureaucrat bb("Bob", 147);
		std::cout << ba;
		std::cout << bb;

		// create forms with INTERN worker
		Intern worker;
		AForm *presi;
		AForm *robo;
		AForm *shrub;
		presi = worker.makeForm("presidential pardon", "somewho");
		robo = worker.makeForm("robotomy request", "Gusto");
		shrub = worker.makeForm("shrubbery creation", "somewhere");		
		std::cout << *presi;
		std::cout << *robo;
		std::cout << *shrub;

		// ### TESTS FROM EX02 ###
		// create form
		// try to execute a non signed form
		std::cout << "### try to execute a non signed form ###\n";
		ba.executeForm(*shrub);
		// try to sign form with lower grade
		std::cout << "### try to sign form with lower grade ###\n";
		bb.signForm(*shrub);
		// sign the form
		std::cout << "### sign the form ###\n";
		ba.signForm(*shrub);
		// try to execute a signed form with lower grade
		std::cout << "### try to execute a signed form with lower grade ###\n";
		bb.executeForm(*shrub);
		// execute the form
		std::cout << "### execute the form ###\n";
		ba.executeForm(*shrub);

		// tests for presidential and robotomy form
		std::cout << "### tests for presidential and robotomy form ###\n";
		ba.signForm(*robo);
		ba.signForm(*presi);
		ba.executeForm(*robo);
		ba.executeForm(*robo);
		ba.executeForm(*robo);
		ba.executeForm(*robo);
		ba.executeForm(*robo);
		ba.executeForm(*presi);
		
		// free forms
		delete presi;
		delete robo;
		delete shrub;

		AForm *invalid;
		invalid = worker.makeForm("abc123", "something");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught Exception: " << e.what() << "\n";
	}
}
