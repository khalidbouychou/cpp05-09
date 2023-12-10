/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:36:54 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/11 00:10:17 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *data = new Data;

    uintptr_t ser = Serializer::serialize(data);
    Data *des = Serializer::deserialize(ser);

    std::cout <<"adress data :" << data << std::endl;
    std::cout <<"adress des  :" << des << std::endl;
    delete data;
    return (0);
}