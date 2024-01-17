/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:17:59 by amenses-          #+#    #+#             */
/*   Updated: 2023/09/30 03:38:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data       data = {0, 0};
    Data*      data_ptr = &data;
    Data*      data_ptr2;

    data_ptr2 = Serializer::deserialize(Serializer::serialize(data_ptr));
    std::cout << data_ptr << std::endl;
    std::cout << data_ptr2 << std::endl;
    if (data_ptr == data_ptr2)
    {
        std::cout << "Equal pointers" << std::endl;
    }
    else
    {
        std::cout << "Different pointers" << std::endl;
    }
    return 0;
}
