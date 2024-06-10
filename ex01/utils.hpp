/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:04:29 by lgosselk          #+#    #+#             */
/*   Updated: 2024/03/22 11:57:32 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <iomanip>
# include <iostream>
# include "Contact.hpp"

int			index_input(void);
std::string	get_response(void);
void		print_ui_search(void);
void		print_wait(std::string str);
void		print_contact(Contact contact[8], int i);
std::string	truncate_word(std::string str, unsigned long max);

#endif