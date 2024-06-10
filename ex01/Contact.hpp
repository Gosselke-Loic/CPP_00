/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:40:25 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/19 15:28:25 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <unistd.h>

class	Contact
{
	private:
		std::string		_secret;
		std::string		_nickname;
		std::string		_last_name;
		std::string		_first_name;
		std::string		_phone_number;
	public:
        Contact(void);
		~Contact(void);
		std::string		get_fname(void) const;
		std::string		get_lname(void) const;
		std::string		get_secret(void) const;
		std::string		get_nickname(void) const;
		void			set_fname(std::string str);
		void			set_lname(std::string str);
		void			set_secret(std::string str);
        std::string		get_phone_number(void) const;
		void			set_nickname(std::string str);
		void			set_phone_number(std::string str);
};

#endif