/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:44 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/15 10:32:38 by ghambrec         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	:	name_(other.name_), grade_(other.grade_)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade_ = other.grade_;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName(void) const
{
	return (name_);
}

int Bureaucrat::getGrade(void) const
{
	return (grade_);
}

void Bureaucrat::incrementGrade(void)
{
	if (grade_ == 1)
		throw GradeTooHighException();
	grade_--;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade_ == 150)
		throw GradeTooLowException();
	grade_++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
