/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:19 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/20 01:07:51 by khbouych         ###   ########.fr       */
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

static int isnumber(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '-' || str[i] == '|' || str[i] == '.')
            i++;
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
static int parse_first_colum(std::string str)
{
    char **tab = ft_split((char *)str.c_str(), '-');
    if (str[4] != '-' || str[7] != '-')
        return (0);
    if (getsizetable(tab) != 3 || tab[0] == NULL || tab[1] == NULL || tab[2] == NULL  || count_char(str, '-') > 2)
        return (0);
    // if (std::atoi(tab[0]) < 2009 || std::atoi(tab[0]) > 2022
    //     ||std::atoi(tab[1]) < 1 || std::atoi(tab[1]) > 12)
    //     return (0);
    if (std::atoi(tab[1]) == 2 &&  (std::atoi(tab[2]) < 0 || std::atoi(tab[2]) > 29))
        return (0);
    if (std::atoi(tab[1]) == 1 || std::atoi(tab[1]) == 3 || std::atoi(tab[1]) == 5
    || std::atoi(tab[1]) == 7 || std::atoi(tab[1]) == 8 || std::atoi(tab[1]) == 10 || std::atoi(tab[1]) == 12)
    {
        if (std::atoi(tab[2]) < 0 || std::atoi(tab[2]) > 31)
            return (0);
    }
    if (std::atoi(tab[1]) == 4 || std::atoi(tab[1]) == 6 || std::atoi(tab[1]) == 9 || std::atoi(tab[1]) == 11)
    {
        if (std::atoi(tab[2]) < 0 || std::atoi(tab[2]) > 30)
            return (0);
    }
    if (!isnumber(tab[2]))
        return (0);
    return (1);
}
static int parse_second_colum(std::string str)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] != '|')
            return 0;
        count++;
        i++;
    }
    if (count > 1)
        return 0;
    return 1;
}

static int parse_third_column(std::string str)
{
    if (count_char(str, '.') > 1 || str[str.length() - 1] == '-'|| count_char(str, '|') > 0
        ||str[0] == '.' || str[str.length() - 1] == '.' || !isnumber(str))
        return 0;
    return 1;
}

std::map<std::string, std::string> storedata(std::string data)
{
    std::map<std::string, std::string> map;
    std::ifstream   file(data);

    if (!file.is_open())
        throw BitcoinExchange::FileException();
    std::string buff;
    std::getline(file, buff);
    std::string key;
    std::string value;
    while (std::getline(file, buff))
    {
        char **tab = ft_split((char *)buff.c_str(), ',');
        key = std::string(tab[0]);
        value = std::string(tab[1]);
        map[key] = value;
    }
    return (map);
}

void printdata(std::map<std::string, std::string> data, char **tab)
{
    std::map<std::string, std::string>::iterator it;
    it = data.upper_bound(std::string(tab[0]));
    if (it != data.begin())
        it--;
    float value = static_cast <float> (std::stod(it->second.c_str()) * std::stod(tab[2]));
    std::cout << tab[0] << " => "<< tab[2] << " = " << value<< std::endl;
}
static void parse_line(char **tab,std::string line)
{
    std::map<std::string, std::string> data;
    data = storedata("data.csv");
    if (parse_first_colum(std::string(tab[0])) == 0)
        std::cout << "Error: bad input => " << line << std::endl;
    else if (parse_second_colum(std::string(tab[1])) == 0)
        std::cout << "Error: bad input => " << line << std::endl;
    else if (parse_third_column(std::string(tab[2])) == 0)
        std::cout << "Error: bad input => " << line << std::endl;
    else if (std::atoi(tab[2]) < 0)
        std::cout << "Error: not a positive number" << std::endl;
    else if (std::atoi(tab[2]) > 1000)
        std::cout << "Error: too large a number" << std::endl;
    else
        printdata(data, tab);
}

static void parse(std::string filename)
{
    std::ifstream   file(filename);
    if (!file.is_open())
        throw BitcoinExchange::FileException();
    std::string line;
    char **tab;
    std::getline(file, line);
    char **firstline  = ft_split((char *)line.c_str(),32);
    if ( !firstline[0] || std::strcmp(firstline[0],"date")  || std::strcmp(firstline[1],"|") || std::strcmp(firstline[2],"value"))
    {
        std::cout << "Error: head of file should be (date | value) or empty file " << std::endl;
        exit(0);
    }
    while (std::getline(file, line))
    {

        tab = ft_split((char *)line.c_str(), 32);
        if (getsizetable(tab) != 3 || tab[0] == NULL || tab[1] == NULL || tab[2] == NULL )
            std::cout << "Error: bad input => " << line << std::endl;
        else
            parse_line(tab,line);
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
