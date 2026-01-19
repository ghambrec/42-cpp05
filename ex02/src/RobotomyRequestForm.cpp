/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:54 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 23:15:49 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:	AForm("RobotomyRequestForm", 72, 45),
		target_(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:	AForm(other), target_(other.target_)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::startExecute(void) const
{
	std::cout << "drrrrrbrrrrrdrrrrrr\n";

    static std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, 1);
    if (dist(gen) == 0)
		std::cout << this->target_ << " has been robotomized successfully!\n";
	else
		std::cout << this->target_ << " couldn't be robotomized!\n";
}
