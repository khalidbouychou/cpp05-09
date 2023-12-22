/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:37:28 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/21 17:33:17 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
        PmergeMe::parse_args(ac,av);
    else
        std::cout << "Error" << std::endl;
    return (0);
}