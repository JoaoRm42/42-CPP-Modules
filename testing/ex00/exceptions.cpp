/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:54:47 by amenses-          #+#    #+#             */
/*   Updated: 2023/09/29 19:54:58 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const char* NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}

const char* ImpossibleException::what() const throw()
{
    return ("impossible");
}
