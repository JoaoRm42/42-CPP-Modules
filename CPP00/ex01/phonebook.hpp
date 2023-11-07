/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:21 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/02 14:33:02 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "contact.hpp"

class Phonebook{
	private:
		Contact Contacts[8];
        int index;
        int max;
	public:
		Phonebook( void );
		~Phonebook( void );
        void AddContact( void );
	    void SearchList ( void );
        void DisplayContact ( void );
};
