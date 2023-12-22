/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:36:57 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/22 14:53:28 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &obj) { *this = obj; }
PmergeMe &PmergeMe::operator=(PmergeMe const &obj)
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

static long int getjcob(int i)
{
    return i == 0 ? 0 : i == 1 ? 1 : (getjcob(i - 1) + (2 * getjcob(i - 2)));
}

static void printargs(int ac ,char **av)
{
    int i = 1;
    while (i <= ac)
        std::cout << " " << av[i++];
    std::cout << " (count : " << ac << ")" ;
}
static void with_vector(int ac, char **av)
{
    clock_t start_p = clock();
    std::vector<std::pair<int, int> > binome;
    int i = 1;
    int reserve = 0;
    if ((ac % 2) == 1)
        reserve = std::atoi(av[ac]);
    while (i < ac)
    {
        binome.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
        i += 2;
    }
    for (int i = 0; i < (int)binome.size(); i++)
    {
        if (binome[i].first < binome[i].second)
            std::swap(binome[i].first, binome[i].second);
    }
    std::sort(binome.begin(), binome.end());
    std::vector<int> v_seq;
    v_seq.push_back(binome[0].second);
    for (int i = 0; i < (int)binome.size(); i++)
        v_seq.push_back(binome[i].first);
    std::vector<long int> jcob;
    for (int i = 0; i >= 0; i++)
    {
        jcob.push_back(getjcob(i));
        if (jcob.back() >= (long)binome.size() + 1)
            break;
    }
    int whenbreak = 1;
    std::vector<int>::iterator vit;
    for (int i = 3; i < (int)jcob.size(); i++)
    {
        long int vjcob = jcob[i];
        // std::cout << vjcob;
        // exit(0);
        while (vjcob > whenbreak)
        {
            if ((vjcob) <= (long int)binome.size())
            {
                vit = std::lower_bound(v_seq.begin(), v_seq.end(), binome[vjcob - 1].second);
                v_seq.insert(vit, binome[vjcob - 1].second);
            }
            vjcob--;
        }
        whenbreak = jcob[i];
    }
    if (reserve)
    {
        vit = std::lower_bound(v_seq.begin(), v_seq.end(), reserve);
        v_seq.insert(vit, reserve);
    }
    std::cout << "\nAfter   : " << " ";
    for (int i = 0; i < (int)v_seq.size(); i++)
        std::cout << v_seq[i] << " ";
    std::cout << "(count : " << v_seq.size() << ")" ;
    clock_t end_p = clock();
    double time = static_cast<double>(end_p - start_p)/1e6 * 1000;
    std::cout << "\nTime to process a range of " << ac << " elements with std::[..] : " << time << " us (vector)" << std::endl;
    std::cout << reserve << std::endl;
}

static void with_deque(int ac, char **av)
{
    clock_t start_p = clock();
    std::deque<std::pair<int, int> > binome;
    int i = 1;
    int reserve = 0;
    if ((ac % 2))
        reserve = std::atoi(av[ac]);
    while (i < ac)
    {
        binome.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
        i += 2;
    }
    for (int i = 0; i < (int)binome.size(); i++)
    {
        if (binome[i].first < binome[i].second)
            std::swap(binome[i].first, binome[i].second);
    }
    std::sort(binome.begin(), binome.end());
    std::deque<int> v_seq;
    v_seq.push_back(binome[0].second);
    for (int i = 0; i < (int)binome.size(); i++)
        v_seq.push_back(binome[i].first);
    std::deque<long int> jcob;
    for (int i = 0; i >= 0; i++)
    {
        jcob.push_back(getjcob(i));
        if (jcob.back() >= (long)binome.size() + 1)
            break;
    }
    int whenbreak = 1;
    std::deque<int>::iterator vit;
    for (int i = 3; i < (int)jcob.size(); i++)
    {
        long int vjcob = jcob[i];
        while (vjcob > whenbreak)
        {
            if ((vjcob) <= (long int)binome.size())
            {
                vit = std::lower_bound(v_seq.begin(), v_seq.end(), binome[vjcob - 1].second);
                v_seq.insert(vit, binome[vjcob - 1].second);
            }
            vjcob--;
        }
        whenbreak = jcob[i];
    }
    if (reserve)
    {
        vit = std::lower_bound(v_seq.begin(), v_seq.end(), reserve);
        v_seq.insert(vit, reserve);
    }
    clock_t end_p = clock();
    double time = static_cast<double>(end_p - start_p)/1e6 * 1000;
    std::cout << "Time to process a range of " << ac << " elements with std::[..] : " << time << " us (deque)" << std::endl;
    std::cout << reserve << std::endl;
}

static int check_args(char **av)
{
    int i = 1;
    while (av[i])
    {
        if (!is_number(av[i]))
            return (0);
        i++;
    }
    return (1);
}
void PmergeMe::parse_args(int ac, char **av)
{
    --ac;
    if (!check_args(av))
    {
        std::cout << "Error" << std::endl;
        return;
    }
    std::cout << "Before  : ";
    printargs(ac ,av);
    with_vector(ac, av);
    with_deque(ac, av);
}
