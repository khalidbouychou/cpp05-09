/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_type.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:06:03 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/10 03:16:17 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void exec_char(std::string  value)
{
    if (value[0] < 32 || value[0] > 126)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
    {
        std::cout << "char: " << "'"<< static_cast<char>(value[0])<<"'"<< std::endl;
        std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value[0]) << ".0"<< std::endl;
    }
}

void exec_int(std::string value)
{
    int res = 0;
    std::istringstream(value) >> res;
    if (static_cast<char>(res) < 32 || static_cast<char>(res) > 126)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(res) << "'" << std::endl;
    std::cout << "int: " << res << std::endl;
    std::cout << "float: " << static_cast<float>(res) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(res) << ".0" << std::endl;
}

void exec_float(std::string  value)
{
    float res = 0;
    if (value == "+inff" || value == "-inff" || value == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << std::endl;
        std::cout << "double: " << value.substr(0,value.length() - 1) << std::endl;
        return ;
    }
    value.erase(value.length() - 1);
    std::istringstream(value) >> res;
    char charr = static_cast<char>(res);
    if (charr < 32 || charr > 126)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << charr << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(res) << std::endl;
    if (checkifhasComma(value) && !checkzero(value))
    {
        std::cout << "float: " << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << std::endl;
    }
    else if (checkzero(value))
    {
        std::cout << "float: " << static_cast<float>(res);
        std::cout << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(res);
        std::cout << ".0" << std::endl;
    }
}

void exec_double(std::string  value)
{
    float res = 0;
    if (value == "-inf" || value == "+inf" || value == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value+"f" << std::endl;
        std::cout << "double: " << value << std::endl;
        return ;
    }
    if (!std::isdigit(value[value.length() - 1]))
    {
        std::cout << "the type conversion is impossible" << std::endl;
        return ;
    }
    std::istringstream(value) >> res;
    char charr = static_cast<char>(res);
    if (charr < 32 || charr > 126)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << charr << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(res) << std::endl;
    if (!iszero(value))
    {
        std::cout << "float: " << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(res) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << ".0" << std::endl;
    }
}
