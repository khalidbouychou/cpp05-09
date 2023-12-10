/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:13:16 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/10 02:52:09 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(std::string const &value) : value(value){}
ScalarConverter::ScalarConverter(ScalarConverter const &sc){*this = sc;}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &sc)
{
    if (this != &sc)
        this->value = sc.value;
    return (*this);
}
ScalarConverter::~ScalarConverter(){}

void  ScalarConverter::convert(std::string value)
{
    if (!value.empty())
    {
        if (v_is_char(value))
            exec_char(value);
        else if (v_is_int(value))
            exec_int(value);
        else if (v_is_float(value))
            exec_float(value);
        else if (v_is_double(value))
            exec_double(value);
        else
            std::cout << "the type conversion is impossible" << std::endl;
    }
    else
        std::cout << "empty" << std::endl;
}
