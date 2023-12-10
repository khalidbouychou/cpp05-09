/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:39:54 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/09 17:52:04 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return (0);
    }
    ScalarConverter::convert(av[1]);
}