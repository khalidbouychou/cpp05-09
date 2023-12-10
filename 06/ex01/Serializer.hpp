/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:59:42 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/10 23:33:33 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>

struct Data
{
    int age;
};

class Serializer
{
    private:
        std::string _str;
        Serializer(void);
        Serializer(Serializer const & src);
        ~Serializer(void);
    public:
        Serializer &operator=(Serializer const & rhs);
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};