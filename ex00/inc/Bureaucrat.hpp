/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:33:42 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/15 10:43:12 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
	private:
		const std::string name_;
		int grade_;

		static constexpr int bestGrade = 1;
		static constexpr int worstGrade = 150;

	public:
		Bureaucrat() = delete;
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		// getter
		const std::string& getName(void) const;
		int getGrade(void) const;
		
		// grade incrementing / decrementing
		void incrementGrade(void);
		void decrementGrade(void);
		
		// exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
