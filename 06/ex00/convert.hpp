/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:40:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/10 03:14:07 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <curses.h>
class ScalarConverter
{
    private:
        std::string value;
        ScalarConverter();
        ScalarConverter(std::string const &value);
        ScalarConverter(ScalarConverter const &sc);
        ScalarConverter &operator=(ScalarConverter const &sc);
        ~ScalarConverter();
    public:
        static void convert( std::string value);
};
bool checkifhasComma(const std::string& value);
bool checkzero(const std::string& value);
bool iszero(const std::string &value);
bool v_is_char(std::string value);
bool v_is_int(std::string value);
bool v_is_float(std::string value);
bool v_is_double(std::string value);
void exec_char(std::string  value);
void exec_int(std::string value);
void exec_float(std::string  value);
void exec_double(std::string  value);