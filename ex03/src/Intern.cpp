/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 08:43:38 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/20 13:27:13 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::createPresi(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobo(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrub(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	struct forms
	{
		const std::string name;
		AForm* (*createForm)(const std::string&);
	};

	static forms data[] = {
		{"presidential pardon", &Intern::createPresi},
		{"robotomy request", &Intern::createRobo},
		{"shrubbery creation", &Intern::createShrub},
	};

	for (forms& d : data)
	{
		if (d.name == formName)
		{
			std::cout << "Intern creates " << formName << "\n";
			return (d.createForm(formTarget));
		}
	}
	throw std::runtime_error("Couldn't find given form name: " + formName);
}
