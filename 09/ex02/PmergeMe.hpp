/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:36:55 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/21 00:01:29 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(PmergeMe const &);
        PmergeMe & operator=(PmergeMe const &);
        ~PmergeMe();
    public :
       static void parse_args(char **av);
};