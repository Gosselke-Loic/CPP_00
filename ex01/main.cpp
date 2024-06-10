/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:26:52 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/22 12:07:46 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	size_t		i;
	PhoneBook	book;
	std::string input;

	input = "";
	while (input.compare("EXIT"))
	{
		i = -1;
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		while (++i < input.length())
			input[i] = (char)std::toupper(input[i]);
		if (input.compare("ADD") == 0)
			book.add();
		else if (input.compare("SEARCH") == 0)
			book.search();
        else if (input.compare("LESS") == 0)
        {
            if (book.getLess() == 0)
            {
                book.setLess(1);
                std::cout << "Boring mode: \033[1;31mactivated\033[0m" << std::endl;
            }
            else
            {
                book.setLess(0);
                std::cout << "Boring mode: \033[1;32mdesactivated\033[0m" << std::endl;
            }
        }
        else if (input.compare("CUPV") == 0)
            book.print_cupv();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
