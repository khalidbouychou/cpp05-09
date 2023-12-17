/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:32 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/17 02:01:39 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
    private:
        std::string     filename;
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange();
    public:
        static void    read_file(std::string filename);
        // static void    print_file();
        class FileException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};
char **ft_split(char *str, char c);