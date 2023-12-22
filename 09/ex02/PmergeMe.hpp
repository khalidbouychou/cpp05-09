/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:36:55 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/22 01:49:50 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
#include <sys/time.h>
#include <time.h>
#include <iomanip>
class PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(PmergeMe const &);
        PmergeMe & operator=(PmergeMe const &);
        ~PmergeMe();
    public :
       static void parse_args(int ac,char **av);
};