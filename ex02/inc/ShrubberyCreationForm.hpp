/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:20 by ghambrec          #+#    #+#             */
/*   Updated: 2026/01/19 17:28:54 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../inc/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target_;

	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		virtual void execute(const Bureaucrat& executor) const override;
};
