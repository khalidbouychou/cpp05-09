/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:25:22 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/26 13:27:03 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void ftfillvector(Span &sp, std::vector<int> &v , unsigned int n)
{
    if ((int)n < 0)
        throw std::out_of_range("n must be > 0");
    for (size_t i = 0; i < n; i++)
        v.push_back(i);

    for (size_t i = 0; i < n; i++)
        sp.addNumber(i);
}
int main()
{
    try
    {
        unsigned int n = 10000;
        Span sp = Span(n);
        std::vector<int> v;
        ftfillvector(sp, v , n);
        std::cout <<sp.shortestSpan()<< std::endl;
        std::cout <<sp.longestSpan()<< std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}