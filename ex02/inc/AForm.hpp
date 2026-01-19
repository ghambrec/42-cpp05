/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:30:38 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 22:28:15 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../inc/Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name_;
		bool isSigned_;
		const int gradeSign_;
		const int gradeExecute_;

		static constexpr int bestGrade = 1;
		static constexpr int worstGrade = 150;

	protected:
		virtual void startExecute(void) const = 0;

	public:
		AForm() = delete;
		AForm(const std::string& name, int gradeSign, int gradeExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		// getter
		const std::string& getName(void) const;
		int getIsSigned(void) const;
		int getGradeSign(void) const;
		int getGradeExecute(void) const;

		// actions
		void beSigned(const Bureaucrat& b);
		void execute(const Bureaucrat& executor) const;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what(void) const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
