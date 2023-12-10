/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:59:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/10 23:36:22 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){}
Serializer::Serializer(Serializer const & src){*this = src;}
Serializer::~Serializer(void){}

Serializer &Serializer::operator=(Serializer const & rhs)
{
    if (this != &rhs)
        this->_str = rhs._str;
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}