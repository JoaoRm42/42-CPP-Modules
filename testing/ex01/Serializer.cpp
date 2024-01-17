/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:24:07 by amenses-          #+#    #+#             */
/*   Updated: 2023/09/30 02:30:12 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const& src)
{
    *this = src;
}

Serializer::~Serializer()
{
}

Serializer& Serializer::operator=(Serializer const& src)
{
    (void)src;
    return *this;
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*       Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
