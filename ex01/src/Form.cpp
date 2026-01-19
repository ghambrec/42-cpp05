/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:30:18 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 15:16:28 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

const char* Form::GradeTooHighException::what(void) const noexcept
{
	return ("Form grade is too high!");
}

const char* Form::GradeTooLowException::what(void) const noexcept
{
	return ("Form grade is too low!");
}

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
	:	name_(name),
		isSigned_(false),
		gradeSign_(gradeSign),
		gradeExecute_(gradeExecute)
{
	if (gradeSign_ < bestGrade || gradeExecute_ < bestGrade)
		throw GradeTooHighException();
	if (gradeSign_ > worstGrade || gradeExecute_ > worstGrade)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	:	name_(other.name_),
		isSigned_(other.isSigned_),
		gradeSign_(other.gradeSign_),
		gradeExecute_(other.gradeExecute_)		
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		isSigned_ = other.isSigned_;
	}
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName(void) const
{
	return (name_);
}

int Form::getIsSigned(void) const
{
	return (isSigned_);
}

int Form::getGradeSign(void) const
{
	return (gradeSign_);
}

int Form::getGradeExecute(void) const
{
	return (gradeExecute_);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os	<< form.getName()
		<< ", form signed:"
		<< form.getIsSigned()
		<< ", gradeSign:"
		<< form.getGradeSign()
		<< ", gradeExecute:"
		<< form.getGradeExecute();

	return (os);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	this->isSigned_ = true;
}
