/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:33 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/08 12:09:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <limits>

class Contact {
	private:
		std::string Firstname;
		std::string Lastname;
		std::string Nickname;
		std::string Phonenumber;
		std::string DarkestSecret;
	public:
		Contact( void );
		~Contact ( void );
        void SetValues ( std::string Fn, std::string Ln, std::string Nick, std::string Phone, std::string Ds );
        int CheckValues( std::string Fn, std::string Ln, std::string Nick, std::string Phone, std::string Ds );
        std::string GetFirst ( void );
        std::string GetLast ( void );
        std::string GetNick ( void );
        std::string GetPhone ( void );
        std::string GetDark ( void );
        std::string SetString( std::string str );
        int ShowContact ( void );
        void ContactShow( void );
};
