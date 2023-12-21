/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:36:57 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/21 01:07:51 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const &obj){*this = obj;}
PmergeMe & PmergeMe::operator=(PmergeMe const &obj)
{
    if (this != &obj)
        *this = obj;
    return (*this);
}

static bool is_number(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
        if (!isdigit(str[i]) || std::atoi(str.c_str()) > 2147483647 || std::atoi(str.c_str()) < 0)
            return (false);
    return (true);
}

static void make_binome (char **av)
{
    std::vector<int> v;
    std::deque<int> d;
    int i = 0;
    while (av[i])
    {
        v.push_back(std::atoi(av[i]));
        i++;
    }
    // std::sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (i % 2 == 0)
            d.push_back(v[i]);
        else
            d.push_front(v[i]);
    }
    for (int i = 0; i < (int)d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;
}
void PmergeMe::parse_args(char **av)
{
    av++;
    while (*av)
    {
        if (!is_number(*av))
            std::cout << "Error" << std::endl;
        av++;
    }
    make_binome(av);
}