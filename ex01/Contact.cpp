/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:28:37 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/18 14:47:19 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{};

Contact::~Contact(void)
{};

std::string		Contact::get_fname(void) const
{
	return (this->_first_name);
}

std::string		Contact::get_lname(void) const
{
	return (this->_last_name);
}

std::string		Contact::get_secret(void) const
{
	return (this->_secret);
}

std::string		Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string		Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

void	Contact::set_fname(std::string str)
{
	this->_first_name = str;
}

void	Contact::set_lname(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::set_phone_number(std::string str)
{
	this->_phone_number = str;
}
