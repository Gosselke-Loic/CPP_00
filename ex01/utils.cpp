/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:04:20 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/22 12:04:22 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void    print_wait(std::string str)
{
	unsigned int microsecond;

	microsecond = 1000000;
	std::cout << str << std::flush;
	std::cout << "." << std::flush;
	usleep(microsecond/2);
	std::cout << "." << std::flush;
	usleep(microsecond/2);
	std::cout << "." << std::endl;
	std::cout << std::endl;
}

std::string get_response(void)
{
	size_t		i = -1;
    std::string	input = "";
	bool		valid = false;

	while (!valid)
	{
		std::cout << "\033[1;33mAre you sure to continue? Y/N\033[0m" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << "Invalid input" << std::endl;
		else if (std::cin.good() && !input.empty())
        {
            while (++i < input.length())
			    input[i] = (char)std::toupper(input[i]);
			if (input.compare("Y") == 0 || input.compare("N") == 0)
				valid = true;
        }	
		else
		{
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
	}
    std::cout << std::endl;
	return (input);
}

std::string	truncate_word(std::string str, unsigned long max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int		index_input(void)
{
	int		input;
	bool	valid;

	valid = false;
	while (!valid)
	{
		std::cout << "Choose your contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input <= 8))
			valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\033[1;31mInvalid index: " \
				"you can retry after 2 seconds\033[0m" << std::endl;
			usleep(2 * 1000000);
		}
	}
    std::cout << std::endl;
	std::cin.ignore();
	return (input);
}

void	print_ui_search(void)
{
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	print_contact(Contact contact[8], int i)
{
	std::string	str;

	str = std::to_string(i);
	std::cout << "|" << std::setw(10) << str;
	str = truncate_word(contact[i].get_fname(), 10);
	std::cout << "|" << std::setw(10) << str;
	str = truncate_word(contact[i].get_lname(), 10);
	std::cout << "|" << std::setw(10) << str;
	str = truncate_word(contact[i].get_nickname(), 10);
	std::cout << "|" << std::setw(10) << str;
	std::cout << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
