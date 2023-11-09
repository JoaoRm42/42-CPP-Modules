/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:21 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/08 19:09:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<unistd.h>
#include <cstdio>
#include "contact.hpp"

class Phonebook{
	private:
		Contact Contacts[8];
        int index;
        int max;
	public:
		Phonebook( void );
		~Phonebook( void );
        int AddContact( void );
	    int SearchList ( void );
        void DisplayContact ( void );
		int FinalResult( int index );
		int checklist ( int index, std::string intput_str);
};