/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:24:18 by amenses-          #+#    #+#             */
/*   Updated: 2023/10/09 15:32:53 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class   Serializer
{
    private:
        Serializer();
        Serializer(Serializer const&);
        ~Serializer();
        Serializer& operator=(Serializer const&);

    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif
