/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:38:42 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/09 17:27:07 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

class   Base
{
    public:
        virtual ~Base() {};
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif
