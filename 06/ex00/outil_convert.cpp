/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_convert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:04:34 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/10 03:12:30 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

bool checkifhasComma(const std::string& value)
{
    if (value.find('.') != std::string::npos)
        return (true);
    return (false);
}
bool checkzero(const std::string& value)
{
   size_t commapos = value.find('.');
    if (commapos == std::string::npos)
        return false;
    size_t index = commapos + 1;
    while (index < value.length() && value[index] != 'f') {
        if (value[index] != '0')
            return false;
        index++;
    }
    return true;
}

bool iszero(const std::string& value)
{
   int i = 0;
   size_t commapos = value.find('.');
    if (commapos == std::string::npos)
        return false;
    i = commapos + 1;
   while (i < (int)value.length())
   {
        if (value[i] != '0')
            return false;
        i++;
   }
    return (true);
}