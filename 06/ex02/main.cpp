/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:28:36 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/14 20:50:46 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base *base = generate();
    std::cout << "identify by reference  : ";
    identify(base);
    std::cout << "identify by pointer    : ";
    identify(*base);
    delete base;
    return (0);
}