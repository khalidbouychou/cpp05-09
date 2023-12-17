/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:54:59 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/16 19:52:16 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw BitcoinExchange::FileException();
        BitcoinExchange::read_file(av[1]);
        // BitcoinExchange::print_file();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}