/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:26:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/11 23:45:37 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T , typename Function>
void iter(T *array, unsigned int len, Function f)
{
    for (unsigned int i = 0; i < len; i++)
        f(array[i]);
}
