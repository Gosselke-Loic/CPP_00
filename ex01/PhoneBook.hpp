/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:40:51 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/22 11:53:52 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "utils.hpp"
# include "Contact.hpp"

class	PhoneBook
{
	private:
		int			_less;
		int			_index;
		Contact		_contact[8];
		void		print(Contact contact);
        std::string	_get_input(std::string str) const;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		add(void);
		void		search(void);
		int			getLess(void);
		int			getIndex(void);
		void		print_cupv(void);
		void		setLess(int number);
		void		setIndex(int number);
};

#endif