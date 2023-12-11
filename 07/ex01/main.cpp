/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:28 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/11 14:32:32 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    char tab2[] = "Hello";
    float tab3[] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f};
    double tab4[] = {0.1, 1.2, 2.3, 3.4, 4.5};

    iter(tab, 5, display);
    iter(tab2, 5, display);
    iter(tab3, 5, display);
    iter(tab4, 5, display);

    return (0);
}