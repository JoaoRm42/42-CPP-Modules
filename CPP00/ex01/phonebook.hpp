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

class Phonebook{
	private:
		int	index;
		

	public:
		Phonebook( void );
		~Phonebook( void );

	void searchlist ( void );
};
