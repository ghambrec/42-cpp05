/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:30:18 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 17:36:04 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

const char* AForm::GradeTooHighException::what(void) const noexcept
{
	return ("Form grade is too high!");
}

const char* AForm::GradeTooLowException::what(void) const noexcept
{
	return ("Form grade is too low!");
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute)
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

AForm::AForm(const AForm& other)
	:	name_(other.name_),
		isSigned_(other.isSigned_),
		gradeSign_(other.gradeSign_),
		gradeExecute_(other.gradeExecute_)		
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		isSigned_ = other.isSigned_;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName(void) const
{
	return (name_);
}

int AForm::getIsSigned(void) const
{
	return (isSigned_);
}

int AForm::getGradeSign(void) const
{
	return (gradeSign_);
}

int AForm::getGradeExecute(void) const
{
	return (gradeExecute_);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os	<< form.getName()
		<< ", form signed:"
		<< form.getIsSigned()
		<< ", gradeSign:"
		<< form.getGradeSign()
		<< ", gradeExecute:"
		<< form.getGradeExecute()
		<< "\n";

	return (os);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	this->isSigned_ = true;
}
