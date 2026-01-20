/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:54 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 23:28:32 by ghambrec         ###   ########.fr       */
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

void ShrubberyCreationForm::startExecute(void) const
{
	std::string filename = this->target_ + "_shrubbery";

	std::ofstream output(filename);
	if (!output.is_open())
		throw std::runtime_error("Couldn't open shrubbery file: " + filename);
	
	output <<
	"              &&& &&  & &&\n"
	"          && &\\/&\\|& ()|/ @, &&\n"
	"          &\\/(/&/&||/& /_/)_&/_&\n"
	"       &() &\\/&|()|/&\\/ '%\" & ()\n"
	"      &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
	"    &&   && & &| &| /& & % ()& /&&\n"
	"     ()&_---()&\\&\\|&&-&&--%---()~\n"
	"         &&     \\|||\n"
	"                 |||\n"
	"                 |||\n"
	"                 |||\n"
	"           , -=-~  .-^- _\n";
}
