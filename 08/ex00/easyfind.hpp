/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:39:36 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/26 11:12:08 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>

template <typename T>

int		easyfind(T &con, int len)
{
    typename T::iterator it = std::find(con.begin(), con.end(), len);
    if (it == con.end())
        throw std::exception();
    return *it;
}