/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:39:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/26 11:09:35 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>

int main()
{
    std::vector<int> v;
    v.push_back(600);
    v.push_back(300);

    std::deque<int> d;
    d.push_back(1);
    d.push_back(2);

    try
    {
        std::cout <<"vector--> " << easyfind(v,600) << std::endl;
        std::cout <<"deque --> " << easyfind(d, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}