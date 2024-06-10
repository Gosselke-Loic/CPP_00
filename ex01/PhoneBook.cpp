/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:28:49 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/22 12:57:56 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void)
{
	this->setLess(0);
	this->setIndex(0);
	std::cout << "\033[1;33mWelcome to your\033[0m " \
		"\033[1;32mWONDERING\033[0m \033[1;33mretro-futuristic phonebook\033[0m" \
        << std::endl;
	std::cout << std::endl;
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "|                         USES                         |" << std::endl;
	std::cout << "|______________________________________________________|" << std::endl;
	std::cout << "| ADD/add -> To add a new contact.                     |" << std::endl;
	std::cout << "| EXIT/exit -> Exit, \033[1;33mnot recommended.\033[0m                  |" << std::endl;
	std::cout << "| SEARCH/search -> Listing all contacts and select one.|" << std::endl;
	std::cout << "| LESS/less -> No waiting times, can overload the cpu. |" << std::endl;
	std::cout << "________________________________________________________" << std::endl;
	std::cout << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\033[1;31mPlease, help me\033[0m" << std::flush;
	if (this->getLess() == 0)
		print_wait(" ");
}

void	PhoneBook::setLess( int number )
{
	this->_less = number;
}

int	PhoneBook::getLess( void )
{
	return (this->_less);
}

void	PhoneBook::setIndex( int number )
{
	this->_index += number;
}

int	PhoneBook::getIndex( void )
{
	return (this->_index);
}

std::string	PhoneBook::_get_input(std::string str) const
{
	bool valid;
    std::string input;

	input = "";
	valid = false;
	while (!valid)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << "Invalid input" << std::endl;
		else if (std::cin.good() && !input.empty())
			valid = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
	}
	return (input);
}

void	PhoneBook::add(void)
{
	std::string	str;

	if (this->getIndex() > 7)
	{
		std::cout << "Warning!, maximum contacts reached. " \
			"Next contact will remove your oldest contact" << std::endl;
		str = get_response();
	}
	else
		str = "Y";
	if (str.compare("Y") == 0)
	{
		if (this->getLess() == 0)
			print_wait("Executing subroutine to add a contact ");
		this->_contact[this->getIndex() % 8].set_fname(this->_get_input("Enter a first name: "));
		this->_contact[this->getIndex() % 8].set_lname(this->_get_input("Enter a last name: "));
		this->_contact[this->getIndex() % 8].set_nickname(this->_get_input("Enter a nickname: "));
		this->_contact[this->getIndex() % 8].set_phone_number(this->_get_input("Enter a phone number: "));
		this->_contact[this->getIndex() % 8].set_secret(this->_get_input("Enter a secret: "));
		std::cout << std::endl;
		this->setIndex(1);
	}
}

void	PhoneBook::search(void)
{
	int		i;
	int		max;
	int		input;
	bool	valid;

	i = -1;
	input = -1;
	valid = false;
	max = this->getIndex();
	if (this->getLess() == 0)
		print_wait("Executing subroutine to search a contact ");
	if (this->getIndex() == 0)
	{
		std::cout << "\033[1;31mYou don't have any friend\033[0m" << std::endl;
		return ;
	}
	else
	{
		print_ui_search();
		while(++i < max && i != 8)
			print_contact(this->_contact, i);
		input = index_input();
		if (input != -1)
			this->print(this->_contact[input]);
	}
}

void	PhoneBook::print(Contact contact)
{
	if (this->getLess() == 0)
		print_wait("Executing subroutine to print a contact ");
	if (!contact.get_fname().size())
	{
		std::cout << "Cannot print this contact, try again later" << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << "First Name: " << contact.get_fname() << std::endl;
	std::cout << "Last Name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contact.get_secret() << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::print_cupv( void )
{
	std::cout << std::endl;
	std::cout << "Bienvenue au C.U.P.V. (condition d'utilisateur pour personne vivante)" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Ce phonebook (propriete de thronebook Inc.) peut etre utiliser que par des personnes vivantes." << std::endl;
	std::cout << "2. Veuillez ignorer tout message hors de contexte." << std::endl;
	std::cout << "3. Tout contact avec les employers de phonebook est strictement interdit." << std::endl;
	std::cout << "4. Nous nous reservons les droits sur toutes information introduite dand phoneBook" << std::endl;
	std::cout << "5. Toutes infraction ce paye avec la vie." << std::endl;
	std::cout << std::endl;
}