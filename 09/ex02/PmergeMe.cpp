/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:36:57 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/22 17:30:25 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
//---------------------------------------Canonical-form--------------------------------------------------------------------------
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &obj) { *this = obj; }
PmergeMe &PmergeMe::operator=(PmergeMe const &obj)
{
    if (this != &obj)
        *this = obj;
    return (*this);
}
//----------------------------------------Start-Program----------------------------------------------------------------------------
static bool is_number(std::string str)
{
    if (str.empty())
        return false;
    for (int i = 0; i < (int)str.length(); i++)
        if (!isdigit(str[i]) || std::atoi(str.c_str()) > 2147483647 || std::atoi(str.c_str()) < 0)
            return (false);
    return (true);
}

static long int getjcob(int i)
{
    return i == 0 ? 0 : i == 1 ? 1 : (getjcob(i - 1) + (2 * getjcob(i - 2)));
}
//--for-vector-----------------------------------------------
static std::vector <int> vector(int ac, char **av)
{
    std::vector<std::pair<int, int> > binome;
    int i = 1;
    int reserve = -1;
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
    if (reserve != -1)
    {
        vit = std::lower_bound(v_seq.begin(), v_seq.end(), reserve);
        v_seq.insert(vit, reserve);
    }
    return v_seq;
}
//------------for-deque------------------------------------------------------------------------------------
static std::deque <int> deque(int ac, char **av)
{
    std::deque<std::pair<int, int> > binome;
    int i = 1;
    int reserve = -1;
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
    std::deque<int> d_seq;
    d_seq.push_back(binome[0].second);
    for (int i = 0; i < (int)binome.size(); i++)
        d_seq.push_back(binome[i].first);
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
                vit = std::lower_bound(d_seq.begin(), d_seq.end(), binome[vjcob - 1].second);
                d_seq.insert(vit, binome[vjcob - 1].second);
            }
            vjcob--;
        }
        whenbreak = jcob[i];
    }
    if (reserve != -1)
    {
        vit = std::lower_bound(d_seq.begin(), d_seq.end(), reserve);
        d_seq.insert(vit, reserve);
    }
    return d_seq;
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
static void printbefore(int ac ,char **av)
{
    std::cout << "Before  : ";
    int i = 1;
    while (i <= ac)
        std::cout  << av[i++] << " ";
}
static void printafter(std::vector <int> vector)
{
    std::cout << "\nAfter   : ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
}
void PmergeMe::parse_args(int ac, char **av)
{
    if (ac < 3|| !check_args(av))
    {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    --ac;
    printbefore(ac ,av);
    //---------------------vector-----------------------------------
    clock_t start_vec = clock();
    std::vector <int> v_seq = vector(ac, av);
    double tvec = static_cast<double>(clock() - start_vec)/1e6 * 1000;
    printafter(v_seq);
    std::cout << "\nTime to process a range of " << ac << " elements with std::[..] : " << tvec << " ms (vector)" << std::endl;
    //----------------------deque-----------------------------------
    clock_t start_deq = clock();
    std::deque <int> d_seq = deque(ac, av);
    double tdeq = static_cast<double>(clock() - start_deq )/1e6 * 1000;
    std::cout << "Time to process a range of " << ac << " elements with std::[..] : " << tdeq << " ms (deque)" << std::endl;
}
