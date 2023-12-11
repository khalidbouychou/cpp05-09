/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:26:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/11 16:16:50 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> void iter(T *array, int length, void (*f)(T const &))
{
    for (int i = 0; i < length; i++)
        f(array[i]);
}

template <typename T> void display(T const &x){std::cout << "Value :" << x << std::endl;}