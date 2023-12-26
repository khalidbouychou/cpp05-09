/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:39:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/26 13:22:22 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(600);
    v.push_back(300);
    try
    {
        std::cout <<"vector--> " << easyfind(v,-600) << std::endl;
    }
    catch (...)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}