/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_type.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:02:56 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/10 03:12:13 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"


bool v_is_char(std::string value)
{
    if (value.length() == 1 && !std::isdigit(value[0]))
        return (true);
    return (false);
}

bool v_is_int(std::string value)
{
    for (int i = 0; i < (int)value.length(); i++)
    {
        if (i == 0 && (value[i] == '-' || value[i] == '+'))
            continue ;
         if (!std::isdigit(value[i]))
            return (false);
    }
    return (true);
}
bool v_is_float(std::string value)
{
    int i = 0;
    int pflag = 0;
    if (value == "+inff" || value == "-inff" || value == "nanf")
        return (true);
    if (value[0] == '-' || value[0] == '+')
        i++;
    while (value[i] && value[i+1])
    {
        if (value[i] == '.')
        {
            if (pflag > 0)
                return (false);
            pflag++;
            i++;
            continue;
        }
         if (!std::isdigit(value[i]))
            return (false);
        i++;
    }
    return (pflag == 1 && value[i] == 'f');
}

bool v_is_double(std::string value)
{
    int i = 0;
    int pflag = 0;
    if (value == "-inf" || value == "+inf" || value == "nan")
        return (true);
    if (value[0] == '-' || value[0] == '+')
        i++;
    while (value[i] && value[i+1])
    {
        if (value[i] == '.')
        {
            if (pflag > 0)
                return (false);
            pflag++;
            i++;
            continue;
        }
        if (!std::isdigit(value[i]))
            return (false);
        i++;
    }
    return (pflag == 1);
}
