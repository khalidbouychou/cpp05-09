/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:19 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/17 02:51:54 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        this->filename = rhs.filename;
    }
    return (*this);
}

//-------
static int getsizetable(char **tab)
{
    int i = 0;
    while (tab[i])
        i++;
    return (i);
}

static int count_char(std::string str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {

            if (str[i] == c)
                count++;
        i++;
    }
    return (count);
}

static int parse_first_colum(std::string str)
{
    char **tab = ft_split((char *)str.c_str(), '-');
    if (str[4] != '-' || str[7] != '-')
        return (0);
    if (getsizetable(tab) != 3 || tab[0] == NULL || tab[1] == NULL || tab[2] == NULL  || count_char(str, '-') > 2)
        return (0);
    if (std::atoi(tab[0]) < 2009 || std::atoi(tab[0]) > 2022
        ||std::atoi(tab[1]) < 1 || std::atoi(tab[1]) > 12)
        return (0);
    if (std::atoi(tab[1]) == 2 &&  (std::atoi(tab[2]) < 0 || std::atoi(tab[2]) > 29))
        return (0);
    if (std::atoi(tab[1]) == 1 || std::atoi(tab[1]) == 3 || std::atoi(tab[1]) == 5 || std::atoi(tab[1]) == 7 || std::atoi(tab[1]) == 8 || std::atoi(tab[1]) == 10 || std::atoi(tab[1]) == 12)
    {
        if (std::atoi(tab[2]) < 0 || std::atoi(tab[2]) > 31)
            return (0);
    }
    if (std::atoi(tab[1]) == 4 || std::atoi(tab[1]) == 6 || std::atoi(tab[1]) == 9 || std::atoi(tab[1]) == 11)
    {
        if (std::atoi(tab[2]) < 0 || std::atoi(tab[2]) > 30)
            return (0);
    }
    return (1);
}
static void parse_line(char **tab)
{
    if (parse_first_colum(std::string(tab[0])) == 0)
        std::cout << "Error: line " << tab[0] << std::endl;
    // if (parse_second_colum(std::string(tab[1])) == 0)
    //     std::cout << "Error: line " << tab[1] << std::endl;
    // if (parse_third_colum(std::string(tab[2])) == 0)
    //     std::cout << "Error: line " << tab[2] << std::endl;
}

static void parse(std::string filename)
{
    std::ifstream   file(filename);
    if (!file.is_open())
        throw BitcoinExchange::FileException();
    std::string line;
    char **tab;

    std::getline(file, line);
    // int i = 0;
    while (std::getline(file, line))
    {

        tab = ft_split((char *)line.c_str(), 32);
        if (getsizetable(tab) != 3 || tab[0] == NULL || tab[1] == NULL || tab[2] == NULL )
            std::cout << "Error: line " << line << std::endl;
        parse_line(tab);
    }
}

void BitcoinExchange::read_file(std::string filename)
{
    parse(filename);
}
//------


const char *BitcoinExchange::FileException::what() const throw()
{
    return ("FileException: File not found");
}
