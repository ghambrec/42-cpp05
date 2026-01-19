/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:44 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 17:45:43 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

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
	os	<< bureaucrat.getName() 
		<< ", bureaucrat grade " 
		<< bureaucrat.getGrade() 
		<< "\n";

	return (os);
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout	<< this->getName()
					<< " signed "
					<< form.getName()
					<< "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->getName() 
					<< " couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< '\n';
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout	<< this->getName()
					<< " executed "
					<< form.getName()
					<< "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->getName()
					<< " couldn't execute "
					<< form.getName()
					<< ", reason: "
					<< "\n";
	}
}