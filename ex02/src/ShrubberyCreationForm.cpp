/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:54 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 17:37:36 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	AForm("ShrubberyCreationForm", 145, 137),
		target_(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:	AForm(other), target_(other.target_)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::cout << "TODO\n";
	(void) executor;
}
