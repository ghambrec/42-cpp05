/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:44 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/14 19:20:34 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const noexcept
{
	return ("Bureaucrat grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const noexcept
{
	return ("Bureaucrat grade is too low!");
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:	name_(name), grade_(grade)
{
	if (grade_ < bestGrade)
		throw GradeTooHighException();
	if (grade_ > worstGrade)
		throw GradeTooLowException();
}

