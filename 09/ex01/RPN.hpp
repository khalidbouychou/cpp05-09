/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:16:46 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/20 01:18:57 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>


class RPN
{
    private:
        RPN();
        RPN(RPN const &src);
        ~RPN();
        RPN &operator=(RPN const &rhs);
    public :
        static void calculate(std::string str);
};